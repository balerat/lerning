#include <iostream>
// The copy constructor
// If you do not provide one cpp will create a public implicit copy constructor
// We can define are own copy constructor

class Fraction
{
private:
  int m_numerator{ 0 };
  int m_denominator{ 1 };

public:
  // Default constructor
  Fraction(int numerator=0, int denominator=1)
    : m_numerator{numerator}, m_denominator{denominator}
  {  
  }
  
  // Copy constructor
  Fraction(const Fraction& fraction)
    : m_numerator{fraction.m_numerator}
    , m_denominator{fraction.m_denominator}
  {
    std::cout << "Copy constructor called\n"; // just to prove it works
  }
  // Copy constructor should have no effects beyond copying
  // Prefer the implicit copy constructor, unless you have a specific reason to create your own
  // If you write your own, the parameter should be a const lvalue reference
  // We can also request default copy constructor
  Fraction(const Franction& fraction) = default;
  // Or we can prevent object from beeing copied with:
  Fraction(const Fraction& fraction) = delete;
};
// The compiler will replace redundant copy of object it is called copy elision

