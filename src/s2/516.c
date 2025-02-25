#include <stdio.h>

#define ROWS 3
#define COLS 4

void printTable(int table[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", table[i][j]);
            table[i][j] = i*j;
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int myTable[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {51, 61, 71, 81},
    };

    int *p = NULL;

    scanf("%d", p);

    printf("Tabela:\n");
    printTable(myTable, ROWS, COLS);

    return 0;
}
