#include <iostream>
#include <utility>

// Scoped enumeration or enum class
// They won't implicitly convert to integers and the enumerators are only placed into the scope region of the enum 

// You can use using to bring it to scope
constexpr std::string_view getColor(Color color)
{
    using enum Color; // bring all Color enumerators into current scope (C++20)
    // We can now access the enumerators of Color without using a Color:: prefix

    switch (color)
    {
    case black: return "black"; // note: black instead of Color::black
    case red:   return "red";
    case blue:  return "blue";
    default:    return "???";
    }
}

int main()
{
  enum class Color{
    red,
    blue
  };

  enum class Fruit{
    banana,
    apple,
  };

  Color color { Color::red };
  Fruit fruit { Fruit::banana };
// You can still use static cast to map to integer or the inverse
  // Also in cpp 23 use underlying
  std::cout << std::to_underlying(color) << '\n';

  // Favor scoped enum over unscoped enum unless ther's a compelling reason to do otherwise
}
