#include <iostream>
#include <system_error>

// functions overloading let us create same nameed fuction for different type as long as they are identitcal

int add(int x, int y)
{
    return x + y;
}

double add (double x, double y)
{
    return x + y;
}

// overloaded functions are difrenciated by number of param and type of param not return type
int add(int x, int y, int z)
{
    return x + y + z;
}

int add(char, char) = delete; // Delete the use of the function for type char and char
  // If a parameter is given a default argument, all subsequent parameters (to the right) must also be given default arguments
  // A parameter given cannot be redeclared so if the function has a forward declaration put the default arg here otherwise, put the default argument in the function definition
  // It is possible to overload default argument (so for other types)
void print(int x, int y=10) // 10 is the default argument using brace init or () init wont work
{
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n';
}
int main()
{
    
    return 0;
}
