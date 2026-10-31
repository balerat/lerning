#include <iostream>
#include <cmath>
#include <cstdint>
#include <cassert>
#include <algorithm>

// for int exponentation there are no functions
constexpr std::int64_t powint(std::int64_t base, int exp)
{
    assert(exp >= 0 && "powint: exp parameter has negative value");

    // Handle 0 case
    if (base == 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result{1};
    while (exp > 0)
    {
        if (exp & 1) // if exp is odd
            result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}

bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

int main() 
{
    -7 / 4 ; // int division
    constexpr int x { 7 };
    constexpr int y { 4 };
    int a;
    int b;
    std::abs(a - b);
    std::cout << x / static_cast<double>(y) << '\n'; // return float
    // Dividing by 0 cause undifiened behaviour or Nan and Inf
    a = b; // assign
    a += b; // add y to x
    a -= b; // Substract y to x
    a *= b;
    a /= b;
    a %= b;
    a == b;
    a != b;
    a > b;
    a >= b;
    a < b;
    a <= b;
    !b; // == to b == false
    a++; // copy a and increment a then return the copy so it is a copy !!!!! do not mod a
    a--;
    ++a; // increment a return a
    --a; // favor prefix
    double x{ std::pow(3.0, 4.0) }; // 3 to the 4th power
    return 0;
}
