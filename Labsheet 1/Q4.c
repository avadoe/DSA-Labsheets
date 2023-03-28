#include <stdio.h>

void swap(int arr[], int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void rearrange(int arr[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            int j = i;
            while(j > 0 && arr[j - 1] > 0){
                swap(arr, j, j - 1);
                j--;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    rearrange(arr, n);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}