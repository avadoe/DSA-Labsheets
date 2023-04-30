#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bool dp[n + 1][k + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(j == 0)
                dp[i][j] = true;
            dp[i][j] = false;
        }
    }

    // In the dp array, dp[i][j] says whether there is a subsequence of the first i elements with sum = j

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j >= arr[i - 1]){
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if(dp[n][k]){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}