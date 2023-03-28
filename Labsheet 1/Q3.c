#include <stdio.h>
#include <stdbool.h>

#define N 100

int A[N], n, s;
bool used[N];

bool subsetSum(int i, int sum) {
    if (sum == s) {
        printf("POSSIBLE\n");
        for (int j = 0; j < n; j++) {
            if (used[j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
        return true;
    }
    if (i == n) {
        return false;
    }
    used[i] = true;
    if (subsetSum(i + 1, sum + A[i])) {
        return true;
    }
    used[i] = false;
    if (subsetSum(i + 1, sum)) {
        return true;
    }
    return false;
}

int main() 
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &s);
    if (!subsetSum(0, 0)) {
        printf("NOT POSSIBLE\n");
    }
    return 0;
}
