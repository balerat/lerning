#include <iostream>

// in parameter : Argument pass to have info and copied no ref
// out parameter :  ref passe to modify the Argument
// A function parameter that is used only for the purpose of returning information back to the caller is called an out parameter
// They are on the right most part of the function their initial value is not important
// Exemple of out parameter

void getByReference(int& x)
{
  x = 5;
}

int y{};

int main()
{
  getByReference(y);
  std::cout << y << '\n';
}
// Avoid out parameter and prefer pass by reference
// in-out parameter: The function will use the value of the out before overwriting its value
// Use non-const reference when you need to avoid making a return copy of an expensive obecjt
// REMEMBER auto drop const and constexpr
// A top level const is a const to the object itself
// A low level const is a const to the reference of the object or pointer
// If you want a const reference, reapply the const qualifier even when it's not stricly necessary, as it makes your intent clear and helps prevent mistakes
// Auto drops reference but not pointers
// When you want a const pointer, reapply the const qualifier to make it clear
