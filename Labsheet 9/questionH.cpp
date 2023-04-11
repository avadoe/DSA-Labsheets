// DONE

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& A, int n, int m, int mid) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > mid) return false;
        if (sum + A[i] > mid) {
            cnt++;
            sum = A[i];
            if (cnt > m) return false;
        } else {
            sum += A[i];
        }
    }
    return true;
}

int allocateBooks(vector<int>& A, int n, int m) {
    if (n < m) return -1;

    int sum = 0, mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        mx = max(mx, A[i]);
    }

    int lo = mx, hi = sum, ans = INT_MAX;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (isValid(A, n, m, mid)) {
            ans = min(ans, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << allocateBooks(A, n, m) << endl;
    return 0;
}
