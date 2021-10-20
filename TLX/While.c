#include <stdio.h>

int main(){
    char string[100];
    while(scanf("%s", string) != EOF)
        printf("%s\n", string);
    
    return 0;
}