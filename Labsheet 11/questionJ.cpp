// DONE

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool dp[n+1][k+1];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= a[i-1]) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if (dp[n][k]) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
