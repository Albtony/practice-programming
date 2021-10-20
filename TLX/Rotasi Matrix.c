#include <stdio.h>

int main(){
    int row, col, i, j, k;
    scanf("%d %d", &row, &col);

    int arr[row][col], res[col][row];
    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
            scanf("%d", &arr[i][j]);

    k = row - 1;

    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++)
            res[j][k] = arr[i][j];
        k--;
    }

    for(i = 0; i < col; i++){
        for(j = 0; j < row; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
}
