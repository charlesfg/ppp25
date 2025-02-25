#include <stdio.h>
#define pi 3.41516

int fat(int n){
    int f = 1;

    for(int i=1; i <= n; i++){
        f *= i;
    }
    return f;
}

int fat2(int n){
    if(n < 2)
        return 1;
    return n * fat2(n-1);
}

int main(){
    int n;
    printf("Insira um numero:");
    scanf("%d", &n);

    printf("Iterativo: fatorial é: %d\n", fat(n));
    printf("Recursivo: fatorial é: %d\n", fat2(n));
    return 0;
}
 