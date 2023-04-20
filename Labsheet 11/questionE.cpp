// DONE

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 0; i <= n; i++)
        cin >> a[i];

    int dp[n + 1][n + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = 0;
        }
    }

    for(int len = 2; len <= n; len++){
        for(int i = 1; i <= n - len + 1; i++){
            int j = i + len - 1;

            dp[i][j] = INT_MAX;

            for(int k = i; k <= j - 1; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j]);
            }
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}