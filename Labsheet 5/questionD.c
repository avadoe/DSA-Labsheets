#include <stdio.h>

int main() {
    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int count = 0;
    int sum = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];

        if (i - start + 1 == k && sum >= k * t) {
            count++;
        }

        if (i - start + 1 > k) {
            sum -= a[start];
            start++;
        }
    }

    printf("%d\n", count);

    return 0;
}
