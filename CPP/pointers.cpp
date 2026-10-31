#include <iostream>
#include <typeinfo>
#include <string>

// The adress operator & returns the memory adress of its operand
// For object with multiple byte of memory it will return the adress of the first one

// The dereference operator * returns the value at a given memory adress as an lvalue

// Pointers is an object that holds a memory adress as its value for using the adress later
// Here we talk about raw or dumb pointers


int main()
{
  int x {5};
  std::cout << x ; // print value of var x
  std::cout << &x ; // print memory adress of x
  std::cout << *(&x) ; // print value at memory adress of x
  int& ref {x}; // a reference to x
  int* ptr1; // A pointer
  // Always initialize pointers !!!
  int* ptrnull {}; // A null pointer
  int* ptr2 {&x}; // a pointer initialized with the adress of x
  // We can then use them with * to get the value
  std::cout << *ptr2;
  // The type of pointer type must match its pointing value
  // It is not possible to initialize a pointer with a value
  int y {6};
  ptr1 = &y; // changed pointed value of ptr to y
  *ptr1 = 7; // Change the value being pointed at

  // Diff between ref and ptr:
  // - Ref must be init, ref not
  // - Ref are not obj, ptr are
  // - Ref cannot be reseated, ptr can
  // - ref must always be bound to an object
  // - ref are safe(besides dangling ref), ptr are dangerous
  // the adress operator return a pointer
  std::cout << typeid(&x).name() << '\n';
  // pointers are initilized with a null value if not init by adress
  int* ptr {nullptr}; // can use nullptr to init a pointer to be a null ptr
  // We can also pass it to functions someFunction(nullptr);
  // Dereferencing a nullptr results in undefined behaviour
  // We can use nullptr for check
  if (ptr == nullptr)
    std::cout << "ptr is null\n";
  // Conditionals can only be used to check nullptr, not a specific adress
  // To avoid deref a nullptr we can use Conditionals
  if (ptr)
    std::cout << *ptr << '\n';
  // A pointer should either point to an adress or be a nullptr
  // We can use 0 and NULL to define nullptr
  ptr = 0;
  ptr = NULL;
  // Favor references over pointers unless the aditionnales capabilities
  // provided by pointers are needed
  // ptr to const:
  const int z {7};
  const int* ptr3 {&z};
  // We cannot change the value but we can change the adress
  const int w {8};
  ptr3 = &w;
  // const ptr can also be used on non const lvalue
  ptr3 = &x; // but we cannot changed *ptr3 value
  // We can create const ptr that cannot change adress
  int* const ptr4 {&x}; // Like a const variable they must be init with a value

}

  // pass by adress:
void print(int* ptr)
{
  if (ptr)
  {
    std::cout << * ptr << '\n';
  }
}

  // It is better to do it the other way to avoid nesting
void print2(int* ptr)
{
  if (!ptr) // we could also use assert(ptr)
    return;
  std::cout << *ptr << '\n';
}

  // For all these problem it is better to pass by const reference
void print3(const int& ptr)
{
  return;
}
// Prefer pass by reference to pass by adress unless you have a specific reason
// to use pass by adress
// One of its use is to create optional arguments:w
void print4(const int* id=nullptr)
{
  if(id)
    std::cout << "Your ID number is " << *id << ".\n";
  else
    std::cout << "Your ID number is not known. \n";
}
// It is better to use function overloading
// If we wanted to change a pointer adress in a function we can pass it by reference

void changeAdress(int*& refptr)
{
  refptr = nullptr;
}

// Pass by reference
const std::string& getProgramName() // returns a const reference
{
  static const std::string s_programName { "Calculator" };

  return s_programName; // The object exists encore bc static
}
// Reference lifetime extension does not work across function boundaries
// Avoid returning references to non-const local static variable
// Assigning/Init a normal variable with a returned reference makes a copy



// It makes sense to return reference parameter by reference
// Its okay to return a const ref of an r valued by const ref
// The caller can modify values throught the reference:
int& max(int& x, int& y)
{
  return(x > y)? x : y;
}

void testing(int x, int y)
{
  max(x, y) = 7; // Change the value of x or y
}

// Prefer return by reference over return by adress unless the ability to return "no object"
// (using nullptr) is important
