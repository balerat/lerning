#ifndef CONSTANTS_H
#define CONSTANTS_H

//define your own namespace to hold constants
namespace constants
{
    constexpr double pi { 3.14 };
    extern const int g_z{}; // forward declaration for g_z in a cpp file, limits repetition of the header guards
    // down side of this is that we cannot use them for compiled time constant

    // We can write inline variables
    inline constexpr double avogadro { 6.022141 };
    // For global constants prefer definining inline constexpr global variables
}
#endif
