#include <stdio.h>

int *getArray()
{
    int arr[3] = {5, 8, 9};
    return arr;
}

int *getArray2()
{
    int arr[3] = {6, 2, 410};
    return arr;
}

int main()
{
    int *ptr = getArray();
    getArray2();
    // getArray2();
    printf("ptr[0] = %d\n", ptr[0]);
    printf("ptr[1] = %d\n", ptr[1]);
    printf("ptr[2] = %d\n", ptr[2]);
    return 0;
}
