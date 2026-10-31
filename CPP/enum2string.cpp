#include <iostream>
#include <ostream>
#include <string>
#include <string_view>
#include <optional>
// How to keys in string from enum ?
// And how to create enum from string ?
// All here

enum Color
{
  black, // 0
  red, // 1
  blue, // 2
};

constexpr std::string_view getColorName(Color color)
{
  switch (color)
  {
    case black: return "black";
    case red:   return "red";
    case blue:  return "blue";
    default:    return "???";
  }
}

constexpr std::optional<Color> getColorFromString(std::string_view sv)
{
  if (sv == "black") return black;
  if (sv == "red") return red;
  if (sv == "blue") return blue;

  return {};
}

// We can also overload the operator << to print directly
std::ostream& operator<<(std::ostream& out, Color color) // std::ostream is the type of std::out and std::cerr
{
  out << getColorName(color);
  return out;
}

// and for input
std::istream& operator>>(std::istream& in, Color& color)
{
  std::string s{};
  in >> s;

  std::optional<Color> match { getColorFromString(s) };
  if (match)
  {
    color = *match;
    return in;
  }

  in.setstate(std::ios_base::failbit);

  return in;
}

int main()
{
  constexpr Color shirt{ blue };

  std::cout << "Your shirt is " << getColorName(shirt) << '\n';

  int input{};
  std::cin >> input;
  
  if (input < 0 || input > 3)
    std::cout << "Invalid";
  else
  {
    Color shirt2{ red };
  }

  std::string s{};
  std::cin >> s;

  std::optional<Color> shirt3 { getColorFromString(s) };
  // with the overloading now
  std::cout << "Your shirt is " << shirt << '\n';

  Color shirt4{};
  std::cin >> shirt4;
}

