#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int C(int n, int r){
    return tgamma(n + 1)/(tgamma(r + 1) * tgamma(n - r + 1));
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

int countTrailingZeroes(int n){
    int count = 0;
    while(n >= 5){
        n /= 5;
        count += n;
    }
    return count;
}

int countGoodPairs(int arr[], int n){
    int countZeroes[n];

    for(int i = 0; i < n; i++){
        countZeroes[i] = countTrailingZeroes(arr[i]);
    }

    int ans = 0;

    mergeSort(countZeroes, 0, n - 1);

    int minimum = INT16_MAX, maximum = INT16_MIN;
    for(int i = 0; i < n; i++){
        if(countZeroes[i] < minimum){
            minimum = countZeroes[i];
        }
        if(countZeroes[i] > maximum){
            maximum = countZeroes[i];
        }
    }

    int newArr[maximum - minimum + 1];

    for(int i = 0; i < maximum - minimum + 1; i++){
        newArr[i] = 0;
    }

    for(int i = 0; i < n; i++){
        newArr[countZeroes[i] - minimum]++;
    }

    for(int i = 0; i < maximum - minimum + 1; i++){
        ans += C(newArr[i], 2);
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", countGoodPairs(arr, n));
}