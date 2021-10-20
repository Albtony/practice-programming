#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);

    for(int i = num; i > 0; i--)
        if(num % i == 0)
            printf("%d\n", i);
}