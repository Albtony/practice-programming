#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);

    if(num > 0) printf("positif");
    else if(num == 0) printf("nol");
    else printf("negatif");
    return 0;
}