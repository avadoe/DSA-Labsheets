// Segmentation fault for large testcases

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long n, w;
    cin >> n >> w;

    vector<pair<long long, long long> > w_c(n);
    for(int i = 0; i < n; i++){
        long long x, y;
        cin >> x >> y;

        w_c[i].first = x;
        w_c[i].second = y;
    }

    long long dp[n + 1][w + 1];

    for(long long i = 0; i <= n; i++){
        for(long long j = 0; j <= w; j++){
            dp[i][j] = 0;
        }
    }

    for(long long i = 1; i <= n; i++){
        long long wi = w_c[i - 1].first;
        long long ci = w_c[i - 1].second;

        for(long long j = 1; j <= w; j++){
            if(j >= wi){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wi] + ci);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][w] << endl;
    return 0;
}