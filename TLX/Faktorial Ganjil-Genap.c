#include <stdio.h>

int factGagen(int n){
    if(n <= 1) return 1;
    else if (n % 2 == 0) return n/2 * factGagen(n-1);
    else return n * factGagen(n-1);
}

int main(){
    int num;
    scanf("%d", &num);
    printf("%d", factGagen(num));
    return 0;
}