#include <cstdint>
// They are two types of type: Enumerated types and class types
// Example:
#include <cctype>
struct Fraction
{
  int numerator {};
  int denominator {};
}; // Dont forget to end your type def with a semicolon
// Name your program-def types starting with a capital letter and do not use a suffix

// A program-def type used in only one code file should be definied as close to the first point of use as poss
// A program-def type used in multiple code files should be def in header file with the same name as the type and included in each file who needs it

// Unscoped enumeration:
enum Color
{
  red,
  green,
  blue,
};

enum SortOrder
{
  alphabetical, // 0
  alphabeticalReverse, // 1
  numerical, // 2
};
// Unscoped enumeration are named such because they put their enumerator names into the same scope as the enum def itself
// So you can have enumeration colisions

// Prefer putting your enumerators inside a named scope region so the enumerator don't pollute the global namespace
namespace Feeling
{
  enum Feeling
  {
    happy,
    tired,
    blue,
  };
}
// Any non-defined enum are give a value one greater than the previous enum  
enum Animal {
  cat = -3, // -3
  dog, // -2
  pig, // -1
  horse = 5, // 5
  giraffe = 5, // 5
};
//Avoid assigning explicit values to your enumerators unless you have a compelling reason to do so
// an enumerator initialized with none will have 0 value of init even if their is non for itself
// So make the enum representing the 0 the default and if no good exist creaTE "invalid" or "unknown" enum

// You can define underlying type for integral
enum Voiture : std::int8_t
{
  black,
  yellow,
  brown,
};

void sortData(SortOrder order)
{
  switch (order)
  {
    case alphabetical:
      // sort data in forwards alphabetical order
      break;
    case alphabeticalReverse:
      // sort data in backward alphabetical order
      break;
    case numerical:
      break;
  }
}
// They are no implicit type conversion from int to enum, use static cast:
Animal pet { static_cast<Animal>(2) };

int main()
{
  Fraction f { 3, 4};
  Color apple { red };
  Color shirt { green };
  Color cup { blue };
  pet = static_cast<Animal>(2);
  return 0;
}
