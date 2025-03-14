#include <stdio.h>

#define PRINT_INFO(var) \
    printf("[ %02d | %5s]:%5s| addr: %p | val: %d\n", __LINE__, __func__, #var, (void *)&var, var);

void f(int *x)
{
    int a = 5, b = 2;
    PRINT_INFO(a);
    PRINT_INFO(x);
    x = &a;
    PRINT_INFO(*x);
    x++; // faço o apontador x apontar para o endereço seguinte
    PRINT_INFO(*x);
}

int main()
{
    int c = 10;
    PRINT_INFO(c);
    f(&c);
    PRINT_INFO(c);
    return 0;
}
