#include <iostream>
using namespace std;

int main() {
    #if __cplusplus == 199711L
    cout << "C++98";
    #elif __cplusplus == 201103L
    cout << "C++11";
    #elif __cplusplus == 201402L
    cout << "C++14";
    #elif __cplusplus == 201703L
    cout << "C++17";
    #elif __cplusplus == 202002L
    cout << "C++20";
    #elif __cplusplus > 202002L
    cout << "C++23 or later";
    #else
    cout << "pre-standard C++";
    #endif
    return 0;
}
