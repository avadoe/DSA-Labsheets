#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n, int exp) {
    // exp is the place value of the digit we are operating on
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    for(int i = 0; i < n; i++){
        printf("%d ", output[i]);
    }
    printf("\n");
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    int i;

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
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

    radixSort(arr, n);
}