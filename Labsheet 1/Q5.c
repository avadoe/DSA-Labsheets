#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }

    int startRow = 0;
    int startCol = 0;

    int endRow = n - 1;
    int endCol = n - 1;

    int presentNum = 2 * n * n;

    while(presentNum >= 2){
        int row, col;
        for(col = endCol; col >= startCol; col--){
            arr[endRow][col] = presentNum;  
            presentNum -= 2;
        }
        endRow--;

        for(row = endRow; row >= startRow; row--){
            arr[row][startCol] = presentNum;
            presentNum -= 2;
        }
        startCol++;

        for(col = startCol; col <= endCol; col++){
            arr[startRow][col] = presentNum;
            presentNum -= 2;
        }
        startRow++;

        for(row = startRow; row <= endRow; row++){
            arr[row][endCol] = presentNum;
            presentNum -= 2;
        }
        endCol--;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            printf("%3d", arr[i][j]);
            if(arr[i][j] - arr[i][j + 1] == 2 || arr[i][j] - arr[i][j + 1] == -2){
                printf("-");
            }else{
                printf(" ");
            }
        }
        printf("%3d", arr[i][n - 1]);
        printf("\n");
        if (i < n-1) {
            for(int j = 0; j < n; j++){
                if(arr[i][j] - arr[i + 1][j] == 2 || arr[i][j] - arr[i + 1][j] == -2){
                    printf("  | ");
                }
                else{
                    printf("    ");
                }
            }
        }
        printf("\n");
    }
}
