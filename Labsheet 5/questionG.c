#include <stdio.h>
#include <stdlib.h>

#define MAX_N 8

int n, k, minUnfairness;
int buckets[MAX_N];
int sum[MAX_N];

void getUnfairness(int sum[]) {
    int max = 0;
    for (int i = 0; i < k; i++) {
        max = (max > sum[i]) ? max : sum[i];
    }
    if (max < minUnfairness) {
        minUnfairness = max;
    }
}

void backtrack(int bucketIdx) {
    if (bucketIdx == n) {
        getUnfairness(sum);
        return;
    }
    for (int i = 0; i < k; i++) {
        sum[i] += buckets[bucketIdx];
        backtrack(bucketIdx + 1);
        sum[i] -= buckets[bucketIdx];
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &buckets[i]);
    }
    minUnfairness = 1e9;
    backtrack(0);
    printf("%d\n", minUnfairness);
    return 0;
}
