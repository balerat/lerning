#include <iostream>
#include <string>


int main()
{
    std::string name {};
    // std::cin breaks on whitespace so to read from the user use:
    std::getline(std::cin >> std::ws, name); // std::ws is an input manipulator for std::cin
    std::cout << "length of string is " << name.length();
    // Or use std::ssize(name) in c++20
    // Do not pass std::string by value as it makes an expensive copy
    // Prefer avoid returning strings too as it makes and expensive copy
    using namespace std::string_literals; // To access to the s suffix
    // We can make string literal with s suffix
    std::cout << "foo\n"s; // this is not a C-style string but a std::string
    return 0;
}
