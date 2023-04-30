#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // dp[i][j] is the maximum score difference possible if the subset remaining is from index i to index j

    int dp[n][n];
    for(int i = 0; i < n; i++){
        dp[i][i] = arr[i];
    }

    // len = length of subsequence

    for(int len = 2; len <= n; len++){
        for(int i = 0; i < n; i++){
            int j = i + len - 1;

            dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}