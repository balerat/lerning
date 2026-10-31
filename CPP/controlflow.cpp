#include <iostream>


namespace constants
{
    constexpr int minRideHeightCM { 140 };
}

int main()
{
    std::cout << "Enter your height (in cm): ";
    int x{};
    std::cin >> x;

    if (x >= constants::minRideHeightCM)
        std::cout << "You are tall enough to ride.\n";
        // Consider using single statment in block
        // or in alternative put everything ina single line
    else
    { // note addition of block here
        std::cout << "You are not tall enough to ride.\n";
        std::cout << "Too bad!\n";
    }
    // else statment are paired with the last if statment so in case of nested else statment be aware of that in case on dangling else statment
    // to avoid itm enclose if statment in a block so it is seen as such

    // less nested = less errors favor else if also
    if (x < 0)
        std::cout << x << " is negative\n";
    else if (x <= 20) // only executes if x >= 0
        std::cout << x << " is between 0 and 20\n";
    else // only executes if x > 20
        std::cout << x << " is greater than 20\n";

    // nul statment 
    if (x > 10)
        ;


    // favor constepr statment over non constexpr if when the codnitionnal in const expr
    constexpr double gravity{ 9.8 };

    if constexpr (gravity == 9.8)
        std::cout << "gravity is normal. \n";
    else
        std::cout << "We are not on Earth. \n";
    

    // SWITCH STATEMENT
    // isntead of evaluating many cases with if

    switch (x)
    {
    case 1:
        std::cout << "One"; // not idented becaus no block
        break;
    case 2:
        std::cout << "Two"; // if no break will execute everything
        break; // we can use break to stop listing and no block is needed
    default: // always place the default label as the last case in switch block
        std::cout << "Unknown";
        break;
    } // best practice to put return or break sstatment in each cases because will execute everything otherwise


    // if you want to intenationaly fall throught put the argiment to indicatei t
    switch (2)
    {
    case 1:
        std::cout << 1 << '\n';
        break;
    case 2:
        std::cout << 2 << '\n'; // Execution begins here
        [[fallthrough]]; // intentional fallthrough -- note the semicolon to indicate the null statement
    case 3:
        std::cout << 3 << '\n'; // This is also executed
        break;
    }
    // init is not alowed in switch
    switch (1)
    {
        int a; // okay: definition is allowed before the case labels
        int b{ 5 }; // illegal: initialization is not allowed before the case labels

    case 1:
        int y; // okay but bad practice: definition is allowed within a case
        y = 4; // okay: assignment is allowed
        break;

    case 2:
        int z{ 4 }; // illegal: initialization is not allowed if subsequent cases exist
        y = 5; // okay: y was declared above, so we can use it here too
        break;

    case 3:
        break;
    } //If defining variables used in a case statement, do so in a block inside the case.
    return 0;
}

// && and operator
// || or operator
// ! not operator
