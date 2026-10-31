#include <iostream>
#include <iomanip>
#include <cstdint>
#include <bitset>
// void type only for functions
// for function that do not takes arguments 
int getValue() // empty function parameters is an implicit void
{
    int x{};
    std::cin >> x;

    return x;
}
int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;

    return y;
}
// the size of op
int main()
{
    std::cout << sizeof(bool);
    short a; // 16 bits
    int b; // 32 bites
    long int c; // 32 bites
    long long int d; // 64 bites
    unsigned short e;
    unsigned int f; // and same for long and long long
    // fixed with integer
    std::int8_t g; // prefer 16 bites as they are treated as char
    std::int32_t h;
    std::uint8_t i;
    float j {5.0f};// f suffix means go to float and not double
    double k {5.0};
    long double l {5.0};
    std::cout << std::setprecision(17); // show 17 digits of precision
    double zero {0.0};
    double posinf { 5.0 / zero };
    double neginf { 5.0 / zero };
    double nan { zero / zero };
    bool b1 { true }; // or can convert 1 to true
    bool b2 { false }; // or can convert 0 to true
    std::cout << std::boolalpha; // print bools as true or false

    // if statement

    int x {};
    x = 1;
    if (x == 0) // /!\ if statement do one execution see blocks after for multiple exec
        std::cout << x;
    else if (x < 2)
        x = 0;
    else
        x = 1;

    // char
    char ch{'4'};
    // static type conversion
    int y = static_cast<int>(5.5);

    // const var
    const double earthGravity {9.8};
    // we should not use const when passing a value or returning one

    std::cout << 5 << '\n';  // 5 (no suffix) is type int (by default)
    std::cout << 5L << '\n'; // 5L is type long
    std::cout << 5u << '\n'; // 5u is type unsigned int
    std::cout << 5.0 << '\n';  // 5.0 (no suffix) is type double (by default)
    std::cout << 5.0f << '\n'; // 5.0f is type float
    double pi { 3.14159 }; // 3.14159 is a double literal in standard notation
    double avogadro { 6.02e23 }; // 6.02 x 10^23 is a double literal in scientific notation
    // to suse octa literal, prefix the literal with a zero
    int octalNumber { 012 };
    // For hexa put 0x as prefix
    int hexaNumber { 0xF };
    // binary literal put 0b in prefix
    int binaryNumber { 0b0001 }; 
    // can use quotation ' for visual separation and for number, they are purely visual
    int prettyBinary { 0b0010'1111'1110 };
    // to output values in binary :
    std::bitset<8> bin1{ 0b1100'0101 };
	std::bitset<8> bin2{ 0xC5 }; // hexadecimal literal for binary 1100 0101
	std::cout << bin1 << '\n' << bin2 << '\n';
	std::cout << std::bitset<4>{ 0b1010 } << '\n'; // create a temporary std::bitset and print it

    // Non-const variables:
    int a { 5 };                 // 5 is a constant expression
    double b { 1.2 + 3.4 };      // 1.2 + 3.4 is a constant expression

    // Const integral variables with a constant expression initializer
    // are compile-time constants:
    const int c { 5 };           // 5 is a constant expression
    const int d { c };           // c is a constant expression
    const long e { c + 2 };      // c + 2 is a constant expression

    // Other const variables are runtime constants:
    const int f { a };           // a is not a constant expression
    const int g { a + 1 };       // a + 1 is not a constant expression
    const long h { a + c };      // a + c is not a constant expression
    const int i { getNumber() }; // getNumber() is not a constant expression

    const double j { b };        // b is not a constant expression
    const double k { 1.2 };      // 1.2 is a constant expression
    // create compiled time const expressions:
    constexpr int sum { 3 + 5 };
    // conditional operator ?:  (cond)?true:false
    constexpr bool inBigClassroom { false };
    constexpr int classSize { inBigClassroom ? 30 : 20}; 
    // in expression we should parenthezied the entire conditional operator

    return 0;
}

// constexpr functions

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

// In cpp 20 we can force copime tile valuation of function
consteval int greater2(int x, int y) // function is now consteval
{
    return (x > y ? x : y);
}


// Uses abbreviated function template (C++20) and `auto` return type to make this function work with any type of value
// See 'related content' box below for more info (you don't need to know how these work to use this function)
consteval auto compileTime(auto value)
{
    return value;
}
int main()
{
    std::cout << greater(5, 6) << '\n';              // may or may not execute at compile-time
    std::cout << compileTime(greater(5, 6)) << '\n'; // will execute at compile-time

    int x { 5 };
    std::cout << greater(x, 6) << '\n';              // we can still call the constexpr version at runtime if we wish

    return 0;
}
#include <type_traits> // for std::is_constant_evaluated

constexpr int someFunction()
{
    if (std::is_constant_evaluated()) // if compile-time evaluation
        return someConstexprFcn();    // calculate some value at compile time
    else                              // runtime evaluation
        return someNonConstexprFcn(); // calculate some value at runtime
}
