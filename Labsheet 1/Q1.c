#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int *B =  (int*)malloc(sizeof(int) * (m * n));

    for(int i = 0; i < m * n; i++){
        scanf("%d", &B[i]);
        if(i > 0){
            B[i] += B[i - 1];
        }
    }

    int ri, ci, rh, ch;
    scanf("%d", &ri);
    scanf("%d", &ci);
    scanf("%d", &rh);
    scanf("%d", &ch);

    for(int i = 0; i < m * n; i++){
        printf("%d ", B[i]);
        if(i % n == n - 1){
            printf("\n");
        }
    }

    if((ri + rh - 1)*(n) + (ci + ch - 1) > n * m){
        printf("IMPOSSIBLE\n");
    }else{
        int sum = 0;
        for(int i = ci; i < ci + ch; i++){
            for(int j = ri; j < ri + rh; j++){
                sum += B[j * n + i];
            }
        }
        printf("%d\n", sum);
    }
    free(B);

    return 0;
}
