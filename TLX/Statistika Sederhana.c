#include <stdio.h>

int main(){
    int reps, elem, max = -100000, min = 100000;
    scanf("%d", &reps);
    for(int i = 0; i < reps; i++){
        scanf("%d", &elem);
        if(elem > max) max = elem;
        if(elem < min) min = elem;
    }

    printf("%d %d", max, min);
    return 0;
}