#include <iostream>
// You can use constructor for user definied conversion
// Only one user conversion is allowed
// An implicit conversion can be trivially coonverted into an explicit definition by using direct list init
// If we want to tell the compiler not to use a constructor for converting type:

class Dollars
{
private:
  int m_dollars{};

public:
  explicit Dollars(int d) // now explicit
    : m_dollars{ d }
  {
  }

  int getDollars() const { return m_dollars; }
};

void print(Dollars d)
{
  std::cout << "$" << d.getDollars();
}

int main()
{
  print(5); // compilation error because Dollars(int) is explicit
  // The explicit constructor can still be used for direct and direct list init
  Dollars d1(4); // ok
  Dollars d2{5}; // ok
  print(Dollars{5}); // ok
  // returning value of function with explicit for constructor will not work
  // make any constructor that accepts a single argument explicit by default
  // do not make copy or move constructor explicit, as these do not perform conversion
  return 0;
}
