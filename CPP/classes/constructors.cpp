#include <iostream>
// Constructor have the same name as the class and must return type void

class Foo
{
private:
  int m_x {};
  int m_y {};

public:
  Foo(int x=0, int y=0) // here's our constructor function that takes two init
    : m_x { x }, m_y { y } // here's our member init list
  // Elelemnt must be init in the order they are defined
  {
    std::cout << "Foo(" << x << ", " << y << ") constructed\n";
  }

  // Constructor can be overloaded
  Foo(double x=0.0, double y=0.0)
  {
  }
  
  // instead of a default constructor with empty body use default
  
  Foo() = default;  // Prefer using this that definin an empty constructor

  void print() const
  {
    std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
  }
};

// The constructor must be non const 
// A class with an user defined default constructor makes the class non-aggregate, whereas an explicitly defaulted default constructor does not.

// Allowing default constructor depends on if you authorized to create class with no init (or default init) or some info to be provided

// Constructor should not be called directly from the body of another function. Doing so will either result
// in a compilation error, or will value init temporary object and then discard it

class Employee
{
private:
    std::string m_name{};
    int m_id{ 0 };

public:
    Employee(std::string_view name)
        : Employee{ name, 0 } // delegate initialization to Employee(std::string_view, int) constructor
  // The downgrade is that we need to hardcode the 0
    {
    }

    Employee(std::string_view name, int id)
        : m_name{ name }, m_id{ id } // actually initializes the members
    {
        std::cout << "Employee " << m_name << " created\n";
    }

};

// When you have multiple constructors, consider whether you can use delegating constructors to reduce duplicate code
// You can also use the default values to reduce the constructor 

// Do not hesitate to use temporary object for clearer code



int main()
{
  Foo foo{ 6, 7 }; //calls Foo(int, int) constructor
  foo.print();

  return 0;
}

// Prefer using the member init list to your members over assigning values in the body of the constructor


// A default constructor is a constructor that accpets no arguments
// Prefer value init over default init for all class types

