#include <iostream>
#include <string_view>
class Employee
{
  int m_id {};
  int m_age {};
  double m_wage {};
};

class Date
{
public:
  int m_day{};
  int m_month{};
  int m_year{};

  void print() //  defines a member function named print
  {
    std::cout << m_year << '\n';
  }

  // member functions can be overloaded
  void print(std::string_view prefix)
  {
    std::cout << prefix << m_day;
  }

  // How to create a const member function
  void print() const // made const cannot change member
  {
    std::cout << m_day;
  }

private:
  int m_private;
  
  void m_print()
  {
    std::cout << "Private functions";
  }
};

struct Person
{
    std::string name{};
    int age{};

    void kisses(const Person& person)
    {
        std::cout << name << " kisses " << person.name << '\n';
    }
};

// member variables and functions can be defined in any order
// member functions can be used with both structs and classes
// however, structs should avoid defining constructor member functions as doing them
// makes them non aggregate

// It is possible to create a class type with no data members
// Prefer using a namespace instead of class type with no data members

// Const member functions may be called on non-const objects
// So a member function that does not changes the state of the object should be made const


// Prefer passing by const ref
// It is possible to have member function overloading to make it const

// The members of a struct are public by default
// Public access have no restriction
// The members of a class are private by default
// they can only be used inside the class (even if a method is called outside)
// we can no longer use agregatte init
// By convention name private variable with m_ prefix
// The protected keyname is for no derived class access

// Classes should generally make member variables private (or protected), and member functions public
// Structs should generally avoid sing access specifiers (all members will default to public)





int main ()
{
  Date date { 4, 10, 21};
  std::cout << date.m_day;
  date.print();
  // It is possible to make const class
  const Date date2 {2, 14, 23};
  // It is then not possible to modify members variables and call functions that do
  // And we can't call non const member function
  Person joe{ "Joe", 29 };
  Person kate{ "Kate", 27 };
  joe.kisses(kate);
  return 0;
}
