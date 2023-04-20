// DONE

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    int dp[n][n];

    /*
    dp[i][j] is the maximum difference that can be obtained between the scores of the two players
    if the remaining sequence is a[i..j]. Here, we assume that Rahul plays optimally.
    */

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[i][i] = arr[i];
    }

    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n; i++){
            int j = l + i - 1;

            dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}