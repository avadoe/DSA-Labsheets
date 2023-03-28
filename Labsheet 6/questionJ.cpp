#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char> st;
    int count = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(')
            st.push(s[i]);
        else{
            if(st.empty()){
                count++;
            }else{
                st.pop();
            }
        }
    }

    count += st.size();

    cout<<count<<endl;
    return 0;
}