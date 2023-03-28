#include <stdio.h>

int atMostK(int arr[], int n, int k){
    int res = 0;
    int l = 0;

    for(int r = 0; r < n; r++){
        k -= arr[r] % 2;

        while (k < 0){
            k += arr[l] % 2;
            l++;
        }
        res += r - l + 1;
    }
    return res;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int ans = atMostK(arr, n, k) - atMostK(arr, n, k - 1);

    printf("%d\n", ans);
    return 0;
}