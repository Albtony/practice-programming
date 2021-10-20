#include <stdio.h>
#include <string.h>
 
void isPalindrome(char str[])
{
    int l = 0;
    int h = strlen(str) - 1;
 
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            printf("BUKAN", str);
            return;
        }
    }
    printf("YA");
}
 
int main()
{
    char string[100];
    scanf("%s", &string);
    isPalindrome(string);
    return 0;
}