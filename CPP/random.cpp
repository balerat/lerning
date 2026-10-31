#include <iostream>
#include <random>
#include <chrono>
// mt199937 generates 32 bit s unsigned integers
// mt19937_64 do it for 64 bits
// Pseudo number generator

unsigned int LCG16()
{
    static unsigned int s_state{0}; // only initialized the first time the func is called

    // Generate the next number
    s_state = 8253729 * s_state + 2396403;
    return s_state % 43768;
}

// Mersene twister is the only algorithm that ships with C++ for C++ 20 and has decent performance and quality
/* Third party libraries for number genreation:
    - Xoshiro faimily and Wyrand for non crypto PRNGs
    - Chacha family for cryptographic non predictable PRNGs
*/
int main()
{
    for (int count{1}; count <= 100; ++ count)
    {
        std::cout << LCG16() << '\t';
        if (count % 10 == 0)
            std::cout << '\n';
    }
    std::mt19937 mt{};
    for (int count{1}; count <= 40; ++count)
    {
        std::cout << mt() << '\t';

        if (count % 5 ==0)
            std::cout << '\n';
    }

    // Let's now create uniform distribution using this PRNGs
    std::uniform_int_distribution die6{1, 6};
    std::cout << die6(mt); // generates a roll of dice
    // Problem is, every time the program is executed, the same seed is applied
    // we need to use the system random device or system clock

    // Seeding with system clock
    std::mt19937 mt2{ static_cast<std::mt19937::result_type>(
        std::chrono::steady_clock::now().time_since_epoch().count())};
    // std::chrono::high_resolution_clock is preferable


    // Seeding with the random device ( Ask the os for a random number )
    std::mt19937 mt3{ std::random_device{}() };

    // prefer random device for applications
    // Only seed a givem PGRNs once and do not resed it
    return 0;
}
