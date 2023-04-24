#include <iostream>
#include <vector>
using namespace std;

long long merge(int arr[], int temp[], int left, int mid, int right) {
    long long inversions = 0;
    int i = left, j = mid, k = left;
    while (i < mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += mid - i;
        }
    }
    while (i < mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return inversions;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);
        inversions += merge(arr, temp, left, mid + 1, right);
    }
    return inversions;
}

int main() {
    int n;
    cin >> n;
    int arr[n], temp[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long inversions = mergeSort(arr, temp, 0, n - 1);
    cout << inversions << endl;
    return 0;
}
