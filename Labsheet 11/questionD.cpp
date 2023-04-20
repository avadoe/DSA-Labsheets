// DONE

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int dp[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = 0;
        }
    }
    int total_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][i] = a[i];
        total_sum += a[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }

    int vidya_score = (dp[0][n-1] + total_sum) / 2;
    int hom_score = total_sum - vidya_score;

    if (vidya_score >= hom_score) {
        cout << "Vidyateja" << endl;
    } else {
        cout << "Hom" << endl;
    }

    return 0;
}
