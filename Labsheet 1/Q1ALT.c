#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int arr[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");

    int oneD[m * n];

    int start = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            oneD[start] = arr[i][j];
            start++;
        }
    }

    for(int i = 1; i < m * n; i++){
        oneD[i] += oneD[i - 1];
    }

    int B[m][n];
    start = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            B[i][j] = oneD[start];
            start++;
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    int ri, ci, rh, ch;
    scanf("%d %d %d %d", &ri, &ci, &rh, &ch);

    if(ri + rh > m || ci + ch > n){
        printf("NOT POSSIBLE\n");
        return 0;
    }

    int ans = 0;
    for(int i = ri; i < rh; i++){
        for(int j = ci; j <= ch; j++){
            ans += B[i][j];
        }
    }

    printf("%d\n", ans);
    return 0;
}