#include <iostream>
#include <vector>
using namespace std;

void reverse(int arr[], int idx) {
    int i = 0, j = idx;
    while (i < j) {
        swap(arr[i], arr[j]);
        i++, j--;
    }
}

int findMax(int arr[], int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

vector<int> pancakeSort(int arr[], int n) {
    vector<int> flips;
    for (int i = n; i > 1; i--) {
        int maxIdx = findMax(arr, i);

        if (maxIdx == i-1) {
            continue;
        }

        if (maxIdx != 0) {
            reverse(arr, maxIdx);
            flips.push_back(maxIdx+1);
        }

        reverse(arr, i-1);
        flips.push_back(i);
    }
    return flips;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> flips = pancakeSort(arr, n);
    cout << flips.size() << endl;
    for (int i = 0; i < flips.size(); i++) {
        cout << flips[i] << " ";
    }
    cout << endl;

    return 0;
}
