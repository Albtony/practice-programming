#include <stdio.h>
#include <math.h>

int main(){
    float num, check;
    scanf("%f", &num);

    check = log(num)/log(2);
    check -= trunc(check);
    if(check == 0) printf("ya");
    else printf("bukan");
}