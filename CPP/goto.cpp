#include <iostream>
#include <cmath>

void printCats(bool skip)
{
    if (skip)
        goto end; // jump forward; statement label 'end' is visible here due to it having function scope

    std::cout << "cats\n";
end: // you cannot jump forward the init of a variable
    ; // statement labels must be associated with a statement
}

int main()
{
    double x{};
tryAgain: // this is a statment label they have function scope
    std::cout << " Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
        goto tryAgain;

    std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';
    return 0;
}
