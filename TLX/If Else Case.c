#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);

    if(num > 9999) printf("puluhribuan");
    else if(num > 999) printf("ribuan");
    else if(num > 99) printf("ratusan");
    else if(num > 9) printf("puluhan");
    else printf("satuan");
    return 0;
}