#include <iostream>

struct Pair // Pair is an aggregate so they can be constexpr
{
    int m_x {};
    int m_y {};

    constexpr int greater() const
    {
        return (m_x > m_y  ? m_x : m_y);
    }
};

int main()
{
    constexpr Pair p { 5, 6 };       // now constexpr
    std::cout << p.greater();        // p.greater() evaluates at runtime or compile-time

    constexpr int g { p.greater() }; // p.greater() must evaluate at compile-time
    std::cout << g;

    // Will not work for classes that are not aggregate. Literal type : objec that can be constexpr
    // If you want your class to be able to be valuated at compile-time, make your member functions and cosntructor
    // constexpr
    // as of cpp 14 member func constexpr can be non-const:class :wq
    
    return 0;
}
