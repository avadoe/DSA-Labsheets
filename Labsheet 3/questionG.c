// COMPLETE

#include <stdio.h>

int getMaxDeduction(int arr[], int n, int target){
    int start = 0;
    int end = n - 1;
    int res = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] <= target){
            res = arr[mid];
            start = mid + 1;
        }else{
            end = mid - 1;
        }
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

    int x = getMaxDeduction(arr, n, k);

    printf("%d", x);
}