#include <iostream>
#include <limits> // for std::numeric_limits
void ignoreLine()
{
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}  // To ignore everything up to and including the next ‘\n’ character, we call

double getDouble()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;

        // Check for failed extraction here (see section below)

        // If there is extraneous input, treat as failure case
        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            ignoreLine(); // remove extraneous input
            continue;
        }

        return x;
    }
}


int main()
{
    /* Wehen to use std::cout vs std::cerr
    Use std::cout for:
        - all conventional user facing text
        - interactive prgm user facing error message
    Use std::cerr for:
        - logfile status and diagnostic info such as warning and errors
        - non interactive prgm for error output only*/
        std::cin.ignore(100, '\n'); // clear up to 100 characters out of the buffer or until a '\n'
 
}
