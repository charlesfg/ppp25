#include <stdio.h>
#include <string.h>

int acha_ocorrencia(char a[], char b[]){

    for(int i=0; i < strlen(a); i++){
        int diferente = 0;
        for(int j=0; j < strlen(b); j++){
            if(a[i+j] != b[j]){
                diferente = 1;
                break;
            }
        }
        if (!diferente){
            return i;
        }
    }
    return -1;
}



int main() {

    char msg[] = "A vaca é gorda!";
    char que[] = "ca";

    printf("%s\n",msg);
    int w = acha_ocorrencia(msg, que);

    printf("A primeira ocorrencia de '%s' em '%s' é no character '%d'\n",msg,que, w);
    printf("msg[w] -> %s\n",&msg[w]);
    return 0;
}
