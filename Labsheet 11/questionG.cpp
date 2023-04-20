// DONE

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int n = s.size(), count = 0;

    bool dp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = false;
        }
    }

    // Palindromes of length 1

    for(int i = 0; i < n; i++){
        dp[i][i] = true;
        count++;
    }

    // Palindromes of length 2

    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            dp[i][i + 1] = true;
            count++;
        }
    }

    // Palindromes of length > 2

    for(int len = 3; len <= n; len++){
        for(int i = 0; i < n - len + 1; i++){
            int j = i + len - 1;

            if(s[i] == s[j] && dp[i + 1][j - 1]){
                dp[i][j] = true;
                count++;                
            }
        }
    }

    cout << count << endl;
    return 0;
}