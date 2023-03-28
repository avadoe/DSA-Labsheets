#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    string s;
    cin >> s;

    unordered_map<string, int> mp;

    int n = s.size();
    int left = 0, right = 0, count = 0;

    while(right < n){
        count++;
        while(count > 10){
            left++;
            count--;
        }

        if(count == 10){
            string sub = s.substr(left, 10);
            mp[sub]++;
        }
        right++;
    }

    int repeated = 0;
    for(auto it: mp){
        if(it.second > 1){
            repeated++;
            cout << it.first << endl;
        }
    }

    if(repeated == 0)
        cout << 0 << endl;
    else{
        cout << repeated << endl;
    }

    return 0;
}