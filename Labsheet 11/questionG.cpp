#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int n = s.size();
    bool dp[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = false;
        }
    }

    // to check if the substring from i to j is a palindrome 
    int ans = 0;

    // Length = 1 Palindromes

    for(int i = 0; i < n; i++){
        dp[i][i] = true;
        ans++;
    }

    // Length = 2 Palindromes

    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            dp[i][i + 1] = true;
            ans++;
        }
    }

    // Greater than length 2 Palindromes

    for(int len = 3; len <= n; len++){
        for(int i = 0; i < n - len + 1; i++){
            int j = i + len - 1;

            if(s[i] == s[j] && dp[i + 1][j - 1]){
                dp[i][j] = true;
                ans++;
            }
        }
    }

    cout << ans << endl;
}