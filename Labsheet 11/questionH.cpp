// DONE

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int n = s.size(), maxLen = 0;

    // dp[i] is the length of the longest RBS ending at position i

    vector<int> dp(n, 0);
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            if(!st.empty() && s[st.top()] == '('){
                int j = st.top();
                st.pop();
                
                int len = i - j + 1;
                if(j > 0){
                    len += dp[j - 1];
                }

                dp[i] = len;
                maxLen = max(maxLen, len);
            }
        }
    }
    cout << maxLen << endl;
    return 0;
}