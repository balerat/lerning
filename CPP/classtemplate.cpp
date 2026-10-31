#include <iostream>
#include <utility>
// It is not possible to overload compound types
// It is not possible to overlaod a function only by return type
// So we use class template

template <typename T=int, typename U=int> // default type int why not
struct Pair 
{
  T first{};
  U second{};
};

int main()
{
  Pair<int, int> p1{5, 6};
  return 0;
}

constexpr int max(Pair<int, int> p)
{
  return (p.first < p.second ? p.second : p.first );
}

template <typename T>
constexpr T max(Pair<T, T> p)
{
  return (p.first < p.second ? p.second : p.first);
}

template <typename T>
void print(T p)
{
  std::cout < p.first; // will only compile if type has first members
}

template <typename T, typename U>
void print2(std::pair<T, U> p)
{
  std::cout << p.first << p.second;
}

int main()
{
  // Class template argument deduction (CTAD)
  std::pair<int, int> p1{ 1,2 };
  std::pair p2{ 3,4 };
  //both are valid
  Pair p3{1,2}; // won't work before cpp 20
  // Using alias template
  using Point = Pair<int>;
}
// But if we don't want to defnine all type in eh alias:

template <typename T>
using Coord = Pair<T>




// So we add type deduction guide
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

// CTAD will not work with non-static member init
// It cannot be used for function parameter too
