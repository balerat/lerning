#include <iostream>
#include <string>

// The value category of an expression indicates whter an expression resolves to a value a function or an object of some kind
// They are three 5 of them, move semantics (glvalue, prvallue, xvalue), lvalue and rvalue
// lvalue --> expr that evaluates to an identifiable object or function
// they can either be modifiable or unmod like constexpr and constexpr
// rvalue are everything else, they return to a value
int x { 4 + 1 }; // int x is a lvalue and 4 + 1 a rvalue
                 // operator = need a mut lvalued on left and rvalue on right
                 // if unsured of what is what use & and look if it 
                 // compiles (it need a lvalue)
/* A reference is an alias for an existing object. Once a reference has 
 * been defined, any operation on the reference is 
 * applied to the object being referenced */
// lvalue reference or just reference
int y { 5 };
int& ref { y }; // ref to x. All referenced must be initialized
                // They must be bind to modifiable lvalue
                // a reference cannot be reseated
                // the reference and its object have independent lifetime
                // But if the object is destroyed before the ref we have a 
                // dangling reference and undefined behaviour
// To bind ref to const value:
const int i { 1 };
const int& ref2 { i };
// It can also be a ref to a modifiable lvalue
// favor lvalue ref to const over lvalue ref to non const unless you want to modify the object being ref
// It is possible to bound const ref to rvalue
// temp object lifetime is inscreased to ref their ref lifetime
// You can also create consexpr ref but they must ref static variables

// Pass by reference :
void prinValue(std::string& y) // type change to std::string&
{
  std::cout << y << '\n';
} // y is destroyed here
// Pass by reference alows us to pass arguments to a function without making compiles
// of those arguments each time the function is called
// Because it is a reference, we can change the value of the passed variable so we can use 
// ref to change value of passed parameter
// Because non const ref only accept non const lvalue prefer using passing by const ref unless
// specific usage

// As a general rule : pass fund type by value and classes or struct types by const reference
// Prefer passing string using std::string_view (by value) instead by const ref unless
// They are C-style strings or std::strings are called by other functions in it




