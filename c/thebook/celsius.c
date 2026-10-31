#include <stdio.h>

int main()
{
    float celsius, fhar;
    int lower, upper, step;
    lower = 0;
    upper = 200;
    step = 20;
    printf("Celsius\tFhar\n");
    while (fhar <= upper)
    {
        celsius = 5.0 / 9.0 * (fhar - 32.0);
        printf("%6.1f\t%6.1f\n", celsius, fhar);
        fhar = fhar + step;
    }
    return 0;
}