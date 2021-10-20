#include <stdio.h>

int main(){
    int arr[100], elem, idx = 0;
    while(scanf("%d", &elem) != EOF){
        arr[idx] = elem;
        idx++;
    }

    for(int i = idx-1; i >= 0; i--)
        printf("%d\n", arr[i]);
}