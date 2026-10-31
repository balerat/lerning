#include <iostream>
#include <bitset>
#include <cmath>
int max(int x, int y)
{
  return (x < y)? y : x;
  // Note: we use < instead of > because std::max uses <
}

template <typename T> // this is the template parameter declaration only viable for the function after it
T max(T x, T y)
{
  return (x < y)? y : x;
}

// Naming convention for type aliases ar TAliases of non obious usage otherwise use T U V ...
// Now on how to use them
int main()
{
  std::cout << max<int>(1,2) << '\n'; // instantiates and class functions max<int>
  std::cout << max<>(1,2) << '\n'; // Using type deduction achieve the same thing
  // Favor the normal function call syntax when making calls to a function instantiated from a function template                                   
  return 0;
  // Beware when using static local variable as they are recreated for each usage of the template
  // Put template definition in header files when you want to use multiple files
  // Use functions templates to write generic code that can work with a wide variety of types whenever you have the need
  // There will be no type overloading for template functions so use static cast or do:
  int x(0);
  x = max<int>(2.5, 2);
}
 
// Multiple type for template
template <typename T, typename U>
auto max2(T x, U y) // Using auto as if we have U as a double it will return a double
{
  return (x < y)? y : x;
}
// Abrievated function templates
auto abrev(auto x, auto y)
{
  return (x < y)? y : x;
}
// Functions template can also be overloaded with new template as for example adding element...
// Non type template parameter is a fixed type param serving as a placeholder for a constexpr value

std::bitset<8> bits{ 0b0000'0101 }; // The <8> is a non-type template parameter

template <int N>
void print() // declare a non-tpe template paameter of type int named N
{
  std::cout << N << '\n';
} // We should use N as the name of an int non-type temlate parameter their good usage is to have consteval functions as using static_assrt :

template <double D>
double getSqrt()
{
  static_assert(D >= 0.0, "getSart(): D must be non-negative" );

  if constexpr (D >= 0)
    return std::sqrt(D);

  return 0.0;
} // We can also use auto for type
