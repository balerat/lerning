#include <iostream>
#include <optional>

// std::optional is a class template type that implements an optional value. That is 
// std::optional<t> can either have a value of type T or not.

std::optional<int> doIntDivision(int x, int y)
{
  if (y == 0)
    return {};
  return x / y;
}

int main()
{
  std::optional<int> result1 { doIntDivision(20, 5) };
  if (result1) // if the function returned a value
    std::cout << *result1 << '\n';
  else
   std::cout << "failed";
}
// Return a std::optional (instead of sentinel value) for functions that fail, unless your function needs tor eturn additional information about why it failed
// std::expected can handle case where a function can return an epected value or an unexpected error code
// Prefer std::optional for optional return types. Prefer overloading in all cases otherwise const T* for T expensive to copy
