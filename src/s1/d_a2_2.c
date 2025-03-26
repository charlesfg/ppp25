#include <stdio.h>


int main(){

    int x = -10;
    unsigned int y = 5;
    
    if (x > y) {
        printf("Uai, que isso!\n");
    }else{
        printf("Ué, mas eu precisava rodar para saber isso?\n");
    }

    printf("unsigned int  x  %u\n",x);
    printf("unsigned int  y  %u\n",y);
    printf("int  x  %d\n",x);
    printf("int  y  %d\n",y);
    
    return 0;
} 


