// DONE

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long n, w;
    cin >> n >> w;

    vector<pair<long long, long long> > arr(n);
    for(long long i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    vector<vector<long long> > dp(n + 1, vector<long long> (w + 1, 0));

    for(long long i = 1; i <= n; i++){
        for(long long j = 1; j <= w; j++){
            if(j >= arr[i - 1].first){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i - 1].first] + arr[i - 1].second);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][w] << endl;
    return 0;
}   