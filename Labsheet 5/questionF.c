#include <stdio.h>

int main() {
    int n, m, i, j, ai, bj;
    long long ans = 0;

    scanf("%d", &n);
    int A[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &m);
    int B[m];
    for (i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }
    
    int ans1 = 0;
    int ans2 = 0;

    for(int i = 0; i < n; i++){
        ans1 ^= A[i];
    }
    for(int j = 0; j < m; j++){
        ans2 ^= B[j];
    }

    if(m % 2 != 0){
        ans ^= ans1;
    }
    if(n % 2 != 0){
        ans ^= ans2;
    }
    
    printf("%lld\n", ans);  
    return 0;
}
