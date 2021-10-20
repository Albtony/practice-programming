#include <stdio.h>

int main(){
    int row1, col1, row2, col2, i, j, k;
    scanf("%d %d %d", &row1, &col1, &col2);
    row2 = col1;

    int arr1[row1][col1], arr2[row2][col2], res[row1][col2];
    for(i = 0; i < row1; i++)
        for(j = 0; j < col1; j++)
            scanf("%d", &arr1[i][j]);
    for(i = 0; i < row2; i++)
        for(j = 0; j < col2; j++)
            scanf("%d", &arr2[i][j]);
    
    for (i = 0; i < row1; i++)
        for (j = 0; j < col2; j++){
            res[i][j] = 0;
            for (k = 0; k < col1; k++)
                res[i][j] += arr1[i][k] * arr2[k][j];
        }
    for(i = 0; i < row1; i++){
        for(j = 0; j < col2; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}