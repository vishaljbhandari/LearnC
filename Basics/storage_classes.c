int global_int;	// declaring the variable which is to be made extern an initial value can also be initialized to x
void autoStorageClass() {
    /*
        The auto Storage Class
            The auto storage class is the default storage class for all local variables.

            This is the default storage class for all the variables declared inside a function or a block. 
            Hence, the keyword auto is rarely used while writing programs in C language. 
            Auto variables can be only accessed within the block/function they have been declared and not outside them (which defines their scope). 
            Of course, these can be accessed within nested blocks within the parent block/function in which the auto variable was declared. 
            However, they can be accessed outside their scope as well using the concept of pointers given here by pointing to the very exact memory location where the variables reside. 
            They are assigned a garbage value by default whenever they are declared.
    */
    printf("Demonstrating auto class\n");

    // declaring an auto variable (simply writing "int a=32;" works as well)
    auto int a = 32;

    // printing the auto variable 'a'
    printf("Value of the variable 'a' declared as auto: %d\n", a);
}

void registerStorageClass() {
    /*
        The register Storage Class
            The register storage class is used to define local variables that should be stored in a register instead of RAM. 
            This means that the variable has a maximum size equal to the register size (usually one word) and can't have the unary '&' operator applied to it (as it does not have a memory location).

        The register should only be used for variables that require quick access such as counters. It should also be noted that defining 'register' does not mean that the variable will be stored in a register. 
            It means that it MIGHT be stored in a register depending on hardware and implementation restrictions.

        This storage class declares register variables that have the same functionality as that of the auto variables. 
            The only difference is that the compiler tries to store these variables in the register of the microprocessor if a free registration is available. 
            This makes the use of register variables to be much faster than that of the variables stored in the memory during the runtime of the program. 
            If a free registration is not available, these are then stored in the memory only. 
            Usually few variables which are to be accessed very frequently in a program are declared with the register keyword which improves the running time of the program. 
            An important and interesting point to be noted here is that we cannot obtain the address of a register variable using pointers.
    */

    printf("Demonstrating register class\n");
    // declaring a register variable
    register char b = 'G';
    // printing the register variable 'b'
    printf("Value of the variable 'b' declared as register: %d\n", b);
}

void externStorageClass() {
    /*
        The extern Storage Class
            The extern storage class is used to give a reference of a global variable that is visible to ALL the program files. When you use 'extern', 
            the variable cannot be initialized however, it points the variable name at a storage location that has been previously defined.

        When you have multiple files and you define a global variable or function, which will also be used in other files, 
            then extern will be used in another file to provide the reference of defined variable or function. 
            Just for understanding, extern is used to declare a global variable or function in another file.
    
        Extern storage class simply tells us that the variable is defined elsewhere and not within the same block where it is used. 
            Basically, the value is assigned to it in a different block and this can be overwritten/changed in a different block as well. 
            So an extern variable is nothing but a global variable initialized with a legal value where it is declared in order to be used elsewhere. 
            It can be accessed within any function/block. 
            Also, a normal global variable can be made extern as well by placing the ‘extern’ keyword before its declaration/definition in any function/block. 
            This basically signifies that we are not initializing a new variable but instead we are using/accessing the global variable only. 
            The main purpose of using extern variables is that they can be accessed between two different files which are part of a large program. 
            For more information on how extern variables work, have a look at this link. 
    */

    printf("Demonstrating extern class\n");
    // telling the compiler that the variable x is an extern variable and has been defined elsewhere (above the main function)
    extern int global_int;

    // printing the extern variables 'global_int'
    printf("Value of the variable 'global_int' declared as extern: %d\n", global_int);

    // value of extern variable x modified
    global_int = 2;

    // printing the modified values of extern variables 'x'
    printf("Modified value of the variable 'global_int' declared as extern: %d\n", global_int);
}

void staticStorageClass() {
    /*
        The static Storage Class
            The static storage class instructs the compiler to keep a local variable in existence during the life-time of the program instead of creating and destroying it each time it comes into and goes out of scope. 
            Therefore, making local variables static allows them to maintain their values between function calls.
            The static modifier may also be applied to global variables. When this is done, it causes that variable's scope to be restricted to the file in which it is declared.
            In C programming, when static is used on a global variable, it causes only one copy of that member to be shared by all the objects of its class.

        This storage class is used to declare static variables which are popularly used while writing programs in C language. 
            Static variables have the property of preserving their value even after they are out of their scope! Hence, static variables preserve the value of their last use in their scope. 
            So we can say that they are initialized only once and exist till the termination of the program. Thus, no new memory is allocated because they are not re-declared. 
            Their scope is local to the function to which they were defined. Global static variables can be accessed anywhere in the program. 
            By default, they are assigned the value 0 by the compiler.
    */

    int i = 0;
    printf("Demonstrating static class\n");
    // using a static variable 'y'
    printf("Declaring 'y' as static inside the loop.\nBut this declaration will occur only once as 'y' is static.\n"
        "If not, then every time the value of 'y' will be the declared value 5 as in the case of variable 'p'\n");

    printf("Loop started:\n");

    for (i = 1; i < 5; i++) {
        // Declaring the static variable 'y'
        static int y = 5;
        // Declare a non-static variable 'p'
        int p = 10;
        // Incrementing the value of y and p by 1
        y++;
        p++;

        // printing value of y at each iteration
        printf("The value of 'y', declared as static, in %d iteration is %d\n", i, y);

        // printing value of p at each iteration
        printf("The value of non-static variable 'p', in %d iteration is %d\n", i, p);
    }
    printf("Loop ended:\n");
}

void StorageClasses() {
	/*
		Storage Classes are used to describe the features of a variable/function. These features basically include the scope,
			visibility and life-time which help us to trace the existence of a particular variable during the runtime of a program.


						
		Syntaxes, To specify the storage class for a variable
			storage_class var_data_type var_name;

	*/

    printf("A program to demonstrate Storage Classes in C\n\n");

    // To demonstrate auto Storage Class
    autoStorageClass();
    PrintSingleLine();
    // To demonstrate register Storage Class
    registerStorageClass();
    PrintSingleLine();
    // To demonstrate extern Storage Class
    externStorageClass();
    PrintSingleLine();
    // To demonstrate static Storage Class
    staticStorageClass();
    PrintSingleLine();
    // exiting
    printf("\n\nStorage Classes demonstrated");
    PrintDoubleLine();
}