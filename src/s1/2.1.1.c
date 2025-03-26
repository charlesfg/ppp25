#include <stdio.h>


int main(){

    int n;
    printf("Insira um número: ");
    scanf("%d", &n);
    
    printf("O número %d é ",n);

    if (n % 2) {
        printf("ímpar\n");
    }else{
        printf("par\n");
    }

    return 10;
} 


