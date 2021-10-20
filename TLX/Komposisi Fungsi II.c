#include <stdio.h>
#include <math.h>

int func(int a, int b, int k, int x){
    if(k == 0) return x;
    else return abs(a * func(a, b, k-1, x) + b);
}

int main(){
    int u, i, o, p;
    scanf("%d %d %d %d", &u, &i, &o, &p);
    printf("%d", func(u, i, o, p));
    return 0;
}