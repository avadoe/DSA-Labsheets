#include <stdio.h>

int subArraysDivisibleByK(int arr[], int n, int k){
    int res = 0, prefixMod = 0;

    int remainders[k];
    for(int i = 0; i < k; i++)
        remainders[k] = 0;
    remainders[0] = 1;

    for(int i = 0; i < n; i++){
        prefixMod = (prefixMod + (arr[i] % k) + k) % k;
        res += remainders[prefixMod];
        remainders[prefixMod]++;
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

    printf("%d\n", subArraysDivisibleByK(arr, n, k));
}   