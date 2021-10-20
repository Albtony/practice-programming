#include <stdio.h>

int main(){
    int reps, elem, sum = 0;
    scanf("%d", &reps);

    for(int i = 0; i < reps; i++){
        scanf(" %d", &elem);
        sum += elem;
    }
    printf("%d", sum);
    return 0;
}