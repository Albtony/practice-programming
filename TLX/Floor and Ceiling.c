#include <stdio.h>
#include <math.h>

int main(){
    float num, floorv, ceilv;
    scanf("%f", &num);  
    floorv = floor(num);
    ceilv = ceil(num);
    printf("%d %d", (int)floorv, (int)ceilv);
}