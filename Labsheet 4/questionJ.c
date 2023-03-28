#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int numberOfOperations(int arr[], int n){
    int sum = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    int target = sum / n;

    int differenceArray[n];
    for(int i = 0; i < n; i++){
        differenceArray[i] = target - arr[i];
    }

    int i = 0, j = n - 1;

    sort(differenceArray, n);

    while(differenceArray[i] < 0){
        count+= -differenceArray[i];
        i++;
    }

    while(differenceArray[j] > 0){
        count += differenceArray[j];
        j--;
    }

    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int ans = numberOfOperations(arr, n);
    printf("%d\n", ans);
    return 0;
}