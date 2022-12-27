/*

 C++14
 From Wikipedia, the free encyclopedia
 Jump to navigationJump to search
 C++14 is a version of the ISO/IEC 14882 standard for the programming language C++. It is intended to be a small extension over C++11, featuring mainly bug fixes and small improvements. Its approval was announced on August 18, 2014.[1] C++14 was released on December 15, 2014.[2]

 Because earlier C++ standard revisions were noticeably late, the name "C++1y" was sometimes used instead until its approval, similarly to how the C++11 standard used to be termed "C++0x" with the expectation of its release before 2010 (although in fact it slipped into 2010 and finally 2011).


 Contents
 1	New language features
 1.1	Function return type deduction
 1.2	Alternate type deduction on declaration[5]
 1.3	Relaxed constexpr restrictions
 1.4	Variable templates
 1.5	Aggregate member initialization
 1.6	Binary literals
 1.7	Digit separators
 1.8	Generic lambdas
 1.9	Lambda capture expressions
 1.10	The attribute [[deprecated]]
 2	New standard library features
 2.1	Shared mutexes and locking
 2.2	Heterogeneous lookup in associative containers
 2.3	Standard user-defined literals
 2.4	Tuple addressing via type
 2.5	Smaller library features
 3	Compiler support
 4	References
 5	External links
 New language features
 These are the features added to the core language of C++14.

 Function return type deduction
 C++11 allowed lambda functions to deduce the return type based on the type of the expression given to the return statement. C++14 provides this ability to all functions. It also extends these facilities to lambda functions, allowing return type deduction for functions that are not of the form return expression;.[3]

 In order to induce return type deduction, the function must be declared with auto as the return type, but without the trailing return type specifier in C++11:

 auto DeduceReturnType();   // Return type to be determined.
 If multiple return expressions are used in the function's implementation, then they must all deduce the same type.[4]

 Functions that deduce their return types can be forward declared, but they cannot be used until they have been defined. Their definitions must be available to the translation unit that uses them.

 Recursion can be used with a function of this type, but the recursive call must happen after at least one return statement in the definition of the function:[4]

 auto Correct(int i)
 {
 if (i == 1)
 return i;             // return type deduced as int

 return Correct(i-1)+i;  // ok to call it now
 }

 auto Wrong(int i)
 {
 if (i != 1)
 return Wrong(i-1)+i;  // Too soon to call this. No prior return statement.

 return i;               // return type deduced as int
 }
 Alternate type deduction on declaration[5]
 In C++11, two methods of type deduction were added. auto was a way to create a variable of the appropriate type, based on a given expression. decltype was a way to compute the type of a given expression. However, decltype and auto deduce types in different ways. In particular, auto always deduces a non-reference type, as though by using std::decay, while auto&& always deduces a reference type. However, decltype can be prodded into deducing a reference or non-reference type, based on the value category of the expression and the nature of the expression it is deducing:[3]

 int   i;
 int&& f();
 auto          x3a = i;     // decltype(x3a) is int
 decltype(i)   x3d = i;     // decltype(x3d) is int
 auto          x4a = (i);   // decltype(x4a) is int
 decltype((i)) x4d = (i);   // decltype(x4d) is int&
 auto          x5a = f();   // decltype(x5a) is int
 decltype(f()) x5d = f();   // decltype(x5d) is int&&
 C++14 adds the decltype(auto) syntax. This allows auto declarations to use the decltype rules on the given expression.

 The decltype(auto) syntax can also be used with return type deduction, by using decltype(auto) syntax instead of auto for the function's return type deduction.[4]

 Relaxed constexpr restrictions
 C++11 introduced the concept of a constexpr-declared function; a function which could be executed at compile time. Their return values could be consumed by operations that require constant expressions, such as an integer template argument. However, C++11 constexpr functions could only contain a single expression that is returned (as well as static_asserts and a small number of other declarations).

 C++14 relaxes these restrictions. Constexpr-declared functions may now contain the following:[3]

 Any declarations except:
 static or thread_local variables.
 Variable declarations without initializers.
 The conditional branching statements if and switch.
 Any looping statement, including range-based for.
 Expressions which change the value of an object if the lifetime of that object began within the constant expression function. This includes calls to any non-const constexpr-declared non-static member functions.
 goto statements are forbidden in C++14 relaxed constexpr-declared functions.

 Also, C++11 stated that all non-static member functions that were declared constexpr were also implicitly declared const, with respect to this. That has since been removed; non-static member functions may be non-const.[6] However, per the restrictions above, a non-const constexpr member function can only modify a class member if that object's lifetime began within the constant expression evaluation.

 Variable templates
 In prior versions of C++, only functions, classes or type aliases could be templated. C++14 now allows the creation of variables that are templated. An example given in the proposal is a variable pi that can be read to get the value of pi for various types (e.g., 3 when read as an integral type; the closest value possible with float, double or long double precision when read as float, double or long double, respectively; etc.).

 The usual rules of templates apply to such declarations and definitions, including specialization.[7][8]

 template<typename T>
 constexpr T pi = T(3.141592653589793238462643383);

 // Usual specialization rules apply:
 template<>
 constexpr const char* pi<const char*> = "pi";
 Aggregate member initialization
 C++11 added member initializers, expressions to be applied to members at class scope if a constructor did not initialize the member itself. The definition of aggregates was changed to explicitly exclude any class with member initializers; therefore, they are not allowed to use aggregate initialization.

 C++14 relaxes this restriction,[3] allowing aggregate initialization on such types. If the braced init list does not provide a value for that argument, the member initializer takes care of it.[9]

 Binary literals
 Numeric literals in C++14 can be specified in binary form.[3] The syntax uses the prefixes 0b or 0B. The syntax is also used in other languages e.g. Java, C#, Swift, Go, Scala, Ruby, Python, OCaml, and as an unofficial extension in some C compilers since at least 2007.[10]

 Digit separators
 In C++14, the single-quote character may be used arbitrarily as a digit separator in numeric literals, both integer literals and floating point literals.[11] This can make it easier for human readers to parse large numbers through subitizing.


 auto integer_literal = 1'000'000;

 auto floating_point_literal = 0.000'015'3;

 auto binary_literal = 0b0100'1100'0110;

 auto silly_example = 1'0'0'000'00;


 Generic lambdas
 In C++11, lambda function parameters need to be declared with concrete types. C++14 relaxes this requirement, allowing lambda function parameters to be declared with the auto type specifier.[7]

 auto lambda = [](auto x, auto y) {return x + y;};
 Concerning auto type deduction, generic lambdas follow the rules of template argument deduction (which are similar, but not identical in all respects[clarification needed]). The code above is equivalent to this:[12]

 struct
 {
 template<typename T, typename U>
 auto operator()(T x, U y) const {return x + y;}
 } lambda{};
 Generic lambdas are essentially templated functor lambdas.

 Lambda capture expressions
 C++11 lambda functions capture variables declared in their outer scope by value-copy or by reference. This means that value members of a lambda cannot be move-only types.[13] C++14 allows captured members to be initialized with arbitrary expressions. This allows both capture by value-move and declaring arbitrary members of the lambda, without having a correspondingly named variable in an outer scope.[7]

 This is done via the use of an initializer expression:

 auto lambda = [value = 1] {return value;};
 The lambda function lambda returns 1, which is what value was initialized with. The declared capture deduces the type from the initializer expression as if by auto.

 This can be used to capture by move, via the use of the standard std::move function:

 std::unique_ptr<int> ptr(new int(10));
 auto lambda = [value = std::move(ptr)] {return *value;};
 The attribute [[deprecated]]
 The deprecated attribute allows marking an entity deprecated, which makes it still legal to use but puts users on notice that use is discouraged and may cause a warning message to be printed during compilation. An optional string literal can appear as the argument of deprecated, to explain the rationale for deprecation and/or to suggest a replacement.

 [[deprecated]] int f();

 [[deprecated("g() is thread-unsafe. Use h() instead")]]
 void g( int& x );

 void h( int& x );

 void test()
 {
 int a = f(); // warning: 'f' is deprecated
 g(a); // warning: 'g' is deprecated: g() is thread-unsafe. Use h() instead
 }
 New standard library features
 Shared mutexes and locking
 C++14 adds a shared timed mutex and a companion shared lock type.[14][15]

 Heterogeneous lookup in associative containers
 The C++ Standard Library defines four associative container classes. These classes allow the user to look up a value based on a value of that type. The map containers allow the user to specify a key and a value, where lookup is done by key and returns a value. However, the lookup is always done by the specific key type, whether it is the key as in maps or the value itself as in sets.

 C++14 allows the lookup to be done via an arbitrary type, so long as the comparison operator can compare that type with the actual key type.[16] This would allow a map from std::string to some value to compare against a const char* or any other type for which an operator< overload is available. It is also useful for indexing composite objects in a std::set by the value of a single member without forcing the user of find to create a dummy object (for example creating an entire struct Person to find a person by name).

 To preserve backwards compatibility, heterogeneous lookup is only allowed when the comparator given to the associative container allows it. The standard library classes std::less<> and std::greater<> are augmented to allow heterogeneous lookup.[17]

 Standard user-defined literals
 C++11 defined the syntax for user-defined literal suffixes, but the standard library did not use any of them. C++14 adds the following standard literals:[16]

 "s", for creating the various std::basic_string types.
 "h", "min", "s", "ms", "us", "ns", for creating the corresponding std::chrono::duration time intervals.
 "if", "i", "il", for creating the corresponding std::complex<float>, std::complex<double> and std::complex<long double> imaginary numbers.
 auto str = "hello world"s; // auto deduces string
 auto dur = 60s;            // auto deduces chrono::seconds
 auto z   = 1i;             // auto deduces complex<double>
 The two "s" literals do not interact, as the string one only operates on string literals, and the one for seconds operates only on numbers.[18]

 Tuple addressing via type
 The std::tuple type introduced in C++11 allows an aggregate of typed values to be indexed by a compile-time constant integer. C++14 extends this to allow fetching from a tuple by type instead of by index.[16] If the tuple has more than one element of the type, a compile-time error results:[19]

 tuple<string, string, int> t("foo", "bar", 7);
 int i = get<int>(t);        // i == 7
 int j = get<2>(t);          // Same as before: j == 7
 string s = get<string>(t);  // Compile-time error due to ambiguity
 Smaller library features
 std::make_unique can be used like std::make_shared for std::unique_ptr objects.[7]

 std::integral_constant gained an operator() overload to return the constant value.[16]

 The class template std::integer_sequence and related alias templates were added for representing compile-time integer sequences, such as the indices of elements in a parameter pack.[20]

 The global std::begin/std::end functions were augmented with std::cbegin/std::cend functions, which return constant iterators, and std::rbegin/std::rend and std::crbegin/std::crend which return reverse iterators.

 The std::exchange function template assigns a new value to a variable and returns the old value.[21]

 New overloads of std::equal, std::mismatch, and std::is_permutation take a pair of iterators for the second range, so that the caller does not need to separately check that the two ranges are of the same length.[22]

 The std::is_final type trait detects if a class is marked final.

 The std::quoted stream I/O manipulator allows inserting and extracting strings with embedded spaces, by placing delimiters (defaulting to double-quotes) on output and stripping them on input, and escaping any embedded delimiters.[23]

 Compiler support
 Clang finished support for C++14 in 3.4 though under the standard name c++1y, and made C++14 the default C++ standard in Clang 6.[24] GCC finished support for C++14 in GCC 5, and made C++14 the default C++ standard in GCC 6.[25] Microsoft Visual Studio 2017 also has implemented "almost all" C++14 features.[26]

 */
