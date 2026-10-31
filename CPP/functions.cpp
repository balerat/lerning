#include <iostream>

void doPrint()
{
    std::cout << "In doPrint()\n";
}

void printValue(int x)
{
    std::cout << x << '\n';
}

int add(int x, int y)
{
    return x + y;
}

void doSomething(int)
{
}

void googleStyle(int /*count*/)
{
}

int add(int x, int y); // forward delcaration

int main()
{
    doPrint();
    printValue(6);
    add(2, 3);

    return 0;
}

int add(int x, int y)
{
    return x + y;
}

