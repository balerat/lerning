#define IDENTIFIER
#define IDENTIFIER substition_text
#define MY_NAME "Baptiste" // the define works only in the file they are
#define PRINT_JOE
#include <iostream>

// Conditional compilation
int main()
{
    std::cout << MY_NAME;
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n";
#endif

// if not def
#ifndef PRINT_BOB // or #if defined(Print_BOB) amd #if ! defined(PRINT_BOB)
    std::cout << "NotBob\n";
#endif

// exclude a block of code
#if 0 // can change to 1 to replace it
    std::cout << "excluded";
#endif
    return 0;
}
