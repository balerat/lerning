#include <iostream>

int main()
{
    // Initialisation
    int width { 5 };
    int a;
    int b = 5; // Copy init
    int c( 6 ); // direct init
    // Cpp 11 prefered
    int d = {7}; // direct list init
    int e = {8}; // init copy
    int f {}; // value init
    [[maybe_unused]] double phi { 1.61803 }; // No warning for unused varaible

    return 0;
}
