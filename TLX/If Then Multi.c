#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    if(num % 2 == 0 && num > 0){
        printf("%d", num);
    }
    return 0;
}