// DONE

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(k + 1);
    dp[0] = 0;

    // dp[i] = the minimum number of coupons to make sum = i

    for(int i = 1; i <= k; i++){
        dp[i] = INF;

        for(int j = 0; j < n; j++){
            if(i - arr[j] >= 0){
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }

    if(dp[k] == INF){
        cout << -1 << endl;
        return 0;
    }

    cout << dp[k] << endl;
    return 0;
}