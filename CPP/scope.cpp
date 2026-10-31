#include <iostream>
#include "scope.h"
// global variable are definied after the includes at the top of each files
int g_x {}; // They can be seen and use everywhere in the file
// prefix g for global is convention

// global variable can be internal linekd or external
// Internal : no linker only identified in one file
// to make then internal we use static
static int g_y {};
// const and constexpr are static by default

// externallinkage for variables
extern const int g_z {};
// no const varible have external linkage by default
// For accessing it in other files we must use forward declaration
extern const int g_z;
// do not use it to define un initialized non const extern varible
// We should avoid the use of global variables
// functions are externaly linked by default but we can 
[[maybe_unused]] static int add(int x, int y)
{
    return x + y;
}
// it is recommanded to give all not externaly used function a static
// They can be definied in namespaces too

// Avoid dynamic initialization whenever possible



namespace Foo
{
    int g {};
}
// we can use ::g_x to access the const if we were shadowing it
// Avoid shadowing const
int main()
{
    // We can use static local variable to make the as global but still usable ina scope
    static int x { 3 };
    // Avoid them adn always initialized them. And do not use them to control a flow
    std::cout << constants::pi;
    return 0;
}


// a Qualifie dname is a name and a scope which defines it
// un unqualified name is not a qualified name


// using namespace std; using statment are defined in a scope only
// prefer explicit of using-statment as it can breaks the ODR easely
