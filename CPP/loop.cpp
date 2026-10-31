#include <iostream>
#include <cstdint> // for fixed-width integers

int main()
{
    int count{1};
    while (count <= 10)
    {
        std::cout << count << ' ';
        ++count;
    }

    std::cout << "done!\n";
    //favor wile true for intentiona linfinite loops
    //integral loop variables should generrally be a singed integral type

    int selection{}; // selection must be declared outside of the do-while-loop, so we can use it later
    // do while are while statment but exectued at least once
    do
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    }
    while (selection < 1 || selection > 4);
    //favor while loop over do while loop when given choice


    // for statement
    for (int i{1}; i <= 10; ++i) // avoir != operator in for loop
    {
        std::cout << i << ' ';
    }

    // we can define multiple counters
    for (int x{0}, y{9}; x < 10; ++x, --y)
        std::cout << x << ' ' << y << '\n';

    // varible used in for loop should be definied inside the for loop

    // you can use break in for and while loop
    // you should use them when they simplify loop logic
    // saem thing with return statement
    for (int count{ 0 }; count < 10; ++count)
    {
        // if the number is divisible by 4, skip this iteration
        if ((count % 4) == 0)
            continue; // go to next iteration

        // If the number is not divisible by 4, keep going
        std::cout << count << '\n';

        // The continue statement jumps to here
    }
    return 0;
}

std::int64_t pow(int base, int exponent)
{
    std::int64_t total{ 1 };

    for (int i{ 0 }; i < exponent; ++i)
        total *= base;

    return total;
}
