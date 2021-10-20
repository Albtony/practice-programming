#include <stdio.h>
#include <math.h>

int main(){
    int x1, y1, x2, y2, dx, dy, res;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    dx = x1 - x2; dy = y1 - y2;
    res = abs(dx) + abs(dy);
    printf("%d", res);

    return 0;
}