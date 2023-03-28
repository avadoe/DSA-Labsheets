// COMPLETE

#include <stdio.h>
#include <stdlib.h>

int firstOcc(int arr[], int start, int end, int key){
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == key && ((mid == 0) || arr[mid - 1] < key)){
            return mid;
        }
        else if(arr[mid] > key){
            return firstOcc(arr, start, mid - 1, key);
        }
        else{
            return firstOcc(arr, mid + 1, end, key);
        }
    }
    return -1;
}

int lastOcc(int arr[], int start, int end, int key){
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == key && ((mid == end) || arr[mid + 1] > key)){
            return mid;
        }
        else if(arr[mid] > key){
            return lastOcc(arr, start, mid - 1, key);
        }
        else{
            return lastOcc(arr, mid + 1, end, key);
        }
    }
    return -1;
}

int countUnique(int arr[], int n){
    int count = 0;
    int i = 0;
    while(i < n){
        int first = firstOcc(arr, 0, n - 1, arr[i]);
        int last = lastOcc(arr, 0, n - 1, arr[i]);

        count++;
        i = last + 1;
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
    int ans = countUnique(arr, n);
    printf("%d\n", ans);
    return 0;
}