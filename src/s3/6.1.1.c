#include <stdio.h>
#include <string.h>

int my_strlen_v1(char s[]){
    int t = 0;
    while(s[t] != 0)
        t++;

    return t;
}

int my_strlen_v2(char s[]){
    char *p = s;
    while(*p++ != 0);
    return p - s - 1;
}

int main() {

    char msg[] = {78, 111,119,32,72,105,114,105,110,103,0};
    printf("%s\n",msg);
    printf("strlen -> %lu\n",strlen(msg));
    printf("my_strlen_v1 -> %d\n",my_strlen_v1(msg));
    printf("my_strlen_v2 -> %d\n",my_strlen_v2(msg));
    return 0;
}
