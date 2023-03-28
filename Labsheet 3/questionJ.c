#include <stdio.h>
#include <stdbool.h>

int maxInArray(int arr[], int n){
    int max = 0;
    for(int i = 0; i < n; i++)
        if(max < arr[i])
            max = arr[i];

    return max;
}

bool canMake(int arr[], int n, int k, int len){
    int count = 0;
    for(int i = 0; i < n; i++){
        count += arr[i]/len;
    }
    return (count >= k);
}

int getMaxLen(int arr[], int n, int k){
    int left = 1;   
    int right = arr[n - 1];

    while(left <= right){
        int half = left + (right - left)/2;

        if(canMake(arr, n, k, half)){
            left = half + 1;
        }else{
            right = half - 1;
        }
    }
    return right;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int x = getMaxLen(arr, n, k);
    printf("%d\n", x);
    return 0;
}