C++ (/ˌsiːˌplʌsˈplʌs/) is a high-level, general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes". The language has expanded significantly over time, and modern C++ has object-oriented, generic, and functional features in addition to facilities for low-level memory manipulation. It is almost always implemented as a compiled language, and many vendors provide C++ compilers, including the Free Software Foundation, LLVM, Microsoft, Intel, Oracle, and IBM, so it is available on many platforms.[6]

C++ was designed with a bias toward system programming and embedded, resource-constrained software and large systems, with performance, efficiency, and flexibility of use as its design highlights.[7] C++ has also been found useful in many other contexts, with key strengths being software infrastructure and resource-constrained applications,[7] including desktop applications, video games, servers (e.g. e-commerce, Web search, or SQL servers), and performance-critical applications (e.g. telephone switches or space probes).[8]

C++ is standardized by the International Organization for Standardization (ISO), with the latest standard version ratified and published by ISO in December 2017 as ISO/IEC 14882:2017 (informally known as C++17).[9] The C++ programming language was initially standardized in 1998 as ISO/IEC 14882:1998, which was then amended by the C++03, C++11 and C++14 standards. The current C++17 standard supersedes these with new features and an enlarged standard library. Before the initial standardization in 1998, C++ was developed by Danish computer scientist Bjarne Stroustrup at Bell Labs since 1979 as an extension of the C language; he wanted an efficient and flexible language similar to C that also provided high-level features for program organization.[10] C++20 is the next planned standard, keeping with the current trend of a new version every three years.[11]

History

Bjarne Stroustrup, the creator of C++, in his AT&T New Jersey office c. 2000
In 1979, Bjarne Stroustrup, a Danish computer scientist, began work on "C with Classes", the predecessor to C++.[12] The motivation for creating a new language originated from Stroustrup's experience in programming for his PhD thesis. Stroustrup found that Simula had features that were very helpful for large software development, but the language was too slow for practical use, while BCPL was fast but too low-level to be suitable for large software development. When Stroustrup started working in AT&T Bell Labs, he had the problem of analyzing the UNIX kernel with respect to distributed computing. Remembering his Ph.D. experience, Stroustrup set out to enhance the C language with Simula-like features.[13] C was chosen because it was general-purpose, fast, portable and widely used. As well as C and Simula's influences, other languages also influenced this new language, including ALGOL 68, Ada, CLU and ML.

Initially, Stroustrup's "C with Classes" added features to the C compiler, Cpre, including classes, derived classes, strong typing, inlining and default arguments.[14]

In 1982, Stroustrup started to develop a successor to C with Classes, which he named "C++" (++ being the increment operator in C) after going through several other names. New features were added, including virtual functions, function name and operator overloading, references, constants, type-safe free-store memory allocation (new/delete), improved type checking, and BCPL style single-line comments with two forward slashes ( //). Furthermore, Stroustrup developed a new, standalone compiler for C++, Cfront.

		In 1985, the first edition of The C++ Programming Language was released, which became the definitive reference for the language, as there was not yet an official standard.[15] The first commercial implementation of C++ was released in October of the same year.[12]

		In 1989, C++ 2.0 was released, followed by the updated second edition of The C++ Programming Language in 1991.[16] New features in 2.0 included multiple inheritance, abstract classes, static member functions, const member functions, and protected members. In 1990, The Annotated C++ Reference Manual was published. This work became the basis for the future standard. Later feature additions included templates, exceptions, namespaces, new casts, and a Boolean type.

		A quiz on C++11 features being given in Paris in 2015
		In 1998, C++98 was released, standardizing the language, and a minor update (C++03) was released in 2003.

		After C++98, C++ evolved relatively slowly until, in 2011, the C++11 standard was released, adding numerous new features, enlarging the standard library further, and providing more facilities to C++ programmers. After a minor C++14 update released in December 2014, various new additions were introduced in C++17, and further changes planned for 2020.[17]

		As of 2019, C++ is now the fourth most popular programming language, behind Java, C, and Python.[18][19]

		On January 3, 2018, Stroustrup was announced as the 2018 winner of the Charles Stark Draper Prize for Engineering, "for conceptualizing and developing the C++ programming language".[20]

		Etymology
		According to Stroustrup, "the name signifies the evolutionary nature of the changes from C".[21] This name is credited to Rick Mascitti (mid-1983)[14] and was first used in December 1983. When Mascitti was questioned informally in 1992 about the naming, he indicated that it was given in a tongue-in-cheek spirit. The name comes from C's ++ operator (which increments the value of a variable) and a common naming convention of using "+" to indicate an enhanced computer program.

		During C++'s development period, the language had been referred to as "new C" and "C with Classes"[14][22] before acquiring its final name.

		Philosophy
		Throughout C++'s life, its development and evolution has been guided by a set of principles:[13]

		It must be driven by actual problems and its features should be immediately useful in real world programs.
		Every feature should be implementable (with a reasonably obvious way to do so).
		Programmers should be free to pick their own programming style, and that style should be fully supported by C++.
		Allowing a useful feature is more important than preventing every possible misuse of C++.
		It should provide facilities for organising programs into separate, well-defined parts, and provide facilities for combining separately developed parts.
		No implicit violations of the type system (but allow explicit violations; that is, those explicitly requested by the programmer).
		User-created types need to have the same support and performance as built-in types.
		Unused features should not negatively impact created executables (e.g. in lower performance).
		There should be no language beneath C++ (except assembly language).
		C++ should work alongside other existing programming languages, rather than fostering its own separate and incompatible programming environment.
		If the programmer's intent is unknown, allow the programmer to specify it by providing manual control.

		Year C++ Standard Informal name
		1998 ISO/IEC 14882:1998[23] C++98
		2003 ISO/IEC 14882:2003[24] C++03
		2011 ISO/IEC 14882:2011[25] C++11, C++0x
		2014 ISO/IEC 14882:2014[26] C++14, C++1y
		2017 ISO/IEC 14882:2017[9] C++17, C++1z
		2020 to be determined C++20,[17] C++2a

		Standardization

		C++ is standardized by an ISO working group known as JTC1/SC22/WG21. So far, it has published five revisions of the C++ standard and is currently working on the next revision, C++20.

		In 1998, the ISO working group standardized C++ for the first time as ISO/IEC 14882:1998, which is informally known as C++98. In 2003, it published a new version of the C++ standard called ISO/IEC 14882:2003, which fixed problems identified in C++98.

		The next major revision of the standard was informally referred to as "C++0x", but it was not released until 2011.[27] C++11 (14882:2011) included many additions to both the core language and the standard library.[25]

		In 2014, C++14 (also known as C++1y) was released as a small extension to C++11, featuring mainly bug fixes and small improvements.[28] The Draft International Standard ballot procedures completed in mid-August 2014.[29]

		After C++14, a major revision C++17, informally known as C++1z, was completed by the ISO C++ Committee in mid July 2017 and was approved and published in December 2017.[30]

		As part of the standardization process, ISO also publishes technical reports and specifications:

		ISO/IEC TR 18015:2006[31] on the use of C++ in embedded systems and on performance implications of C++ language and library features,
		ISO/IEC TR 19768:2007[32] (also known as the C++ Technical Report 1) on library extensions mostly integrated into C++11,
		ISO/IEC TR 29124:2010[33] on special mathematical functions,
		ISO/IEC TR 24733:2011[34] on decimal floating point arithmetic,
		ISO/IEC TS 18822:2015[35] on the standard filesystem library,
		ISO/IEC TS 19570:2015[36] on parallel versions of the standard library algorithms,
		ISO/IEC TS 19841:2015[37] on software transactional memory,
		ISO/IEC TS 19568:2015[38] on a new set of library extensions, some of which are already integrated into C++17,
		ISO/IEC TS 19217:2015[39] on the C++ concepts, integrated into C++20
		ISO/IEC TS 19571:2016[40] on the library extensions for concurrency
		ISO/IEC TS 19568:2017[41] on a new set of general-purpose library extensions
		ISO/IEC TS 21425:2017[42] on the library extensions for ranges, integrated into C++20
		ISO/IEC TS 22277:2017[43] on coroutines
		ISO/IEC TS 19216:2018[44] on the networking library
		ISO/IEC TS 21544:2018[45] on modules
		ISO/IEC TS 19570:2018[46] on a new set of library extensions for parallelism
		More technical specifications are in development and pending approval, including static reflection.[47]
