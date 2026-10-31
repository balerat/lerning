#include <iostream>
// Structures :
#include <cwchar>
struct Employee
{
  int id {};
  int age{};
  double wage {};
};
// A member is a varaible a function or type that belongs to a struct or class
// An agregatte data type is any type that can contain multiple data members
// In C++ an agregateis a C-style array or class type that:
// - No user-dlecared constructor
// - No private or protected non-static data members
// - No virtual functions

struct Something
{
  int x;
  int y{};
  int z {2};
};

// We can drop the returning type if its obvious
Something getSomething()
{
  return {};
}
void printEmployee(const Employee& employee)
{
  std::cout << "ID: " << employee.id << '\n';
}

// Struct with program definied members
struct Company
{
  Employee CEO {};
};
// we can also do nested struct
// In most cases we want our struct to be owners. so no ref no pointer
// Practice safe strcuts don't let member dangle
int main()
{
  Employee john {};

  john.age = 32;
  int newAge = { john.age + 10 };    
  
  // Agregate init:
  Employee frank = {1, 32, 6000.0}; // copy-list init using braced copy-list
  Employee joe {2, 28, 45000.0}; // list init using braced list (preffered)
  const Employee silvy {};
  // Designated init:
  Employee jean{ .age{10}, .wage{40000}};
  // When adding new members to an aggregate put it at the bottom it is safest
  joe = { joe.id, 33, 6000.0 };
  joe = {.id = joe.id, .wage = joe.wage, .age = joe.age};
  Employee loic = joe;
  Something s1;             // No initializer list: s1.x is uninitialized, s1.y and s1.z use defaults
  Something s2 { 5, 6, 7 }; // Explicit initializers: s2.x, s2.y, and s2.z use explicit values (no default values are used)
  Something s3 {};          // Missing initializers: s3.x is value initialized, s3.y and s3.z use defaults
  // Always provide default value for all member
  // For agregate prefer value init instead of default init
  printEmployee(Employee { 14, 28, 18.27});

  // . member selection from pointer 
  // For a ref it is alright
  Employee& ref {jean};
  ref.id = 100;

  //ugly
  Employee* ptr {&jean};
  std::cout << (*ptr).id;
  // Arrow selection operator to select members from a pointer to an object
  std::cout << ptr->id;
  // Prefer the arrow selection operator over the member selection operator .
  return 0;
}

