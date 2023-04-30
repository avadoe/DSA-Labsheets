#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coupons(n);
    for (int i = 0; i < n; i++) {
        cin >> coupons[i];
    }

    vector<int> dp(k+1, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = coupons[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j-coupons[i]]+1);
        }
    }

    if (dp[k] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dp[k] << endl;
    }

    return 0;
}
