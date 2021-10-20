#include <stdio.h>

int toBinary(int n){
    if(N == 1) return 1;
    else if(N % 2 == 1) return toBinary(N/2) + "1";
    else return toBinary + "0";
}

int main(){
    int num;
    scanf("%d", &num);
    printf("%s", toBinary(num));
}