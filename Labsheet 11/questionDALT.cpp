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

    int dp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        dp[i][i] = arr[i];
    }

    // dp[i][j] represents the max score the current player can get if the playing area is a[i.....j]

    for(int len = 2; len <= n; len++){ // this outer loop iterates over all the subarray lengths possible
        for(int i = 0; i < n - len + 1; i++){ // this inner loop iterates over all possible starting indices
            int j = i + len - 1;

            dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]); 
            // if the first element is chosen, the next player will pick optimally from index i + 1, and if the last
            // element is chosen, the next player will pick optimally from first index to last but one index
        }
    }

    int diff = dp[0][n - 1];
    if(diff >= 0){
        cout << "Vidyateja" << endl;
    }
    else {
        cout << "Hom" << endl;
    }

    return 0;
}