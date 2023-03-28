#include <stdio.h>

int nSubArrays(int arr[], int n, int k){
    int map[k];
    for(int i = 0; i < k; i++){
        map[i] = 0;
    }
    map[0] = 1;
    int count = 0;
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        sum = sum % k;

        if(sum < 0)
            sum += k;
        
        count += map[sum];
        map[sum]++;
    }

    return count;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("%d\n", nSubArrays(arr, n, k));
    return 0;
}