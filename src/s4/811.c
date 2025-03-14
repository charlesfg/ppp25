/* print Fahrenheit-Celsius table; version with if */
#include <stdio.h>

void no_pointer()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    while (1)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
        if (fahr > upper)
            break;
    }
    return 0;
}

void pointer()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    while (1)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
        if (fahr > upper)
            break;
    }
    return 0;
}

int main()
{
}