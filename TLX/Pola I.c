#include <stdio.h>

int main(){
    int num, plsdont;
    scanf("%d %d", &num, &plsdont);
    for(int i = 1; i <= num; i++)
        if(i % plsdont == 0) printf("* ");
        else printf("%d ", i);
    return 0;
}