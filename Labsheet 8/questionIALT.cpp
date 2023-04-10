#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> mp;

    int w, l;

    for(int i = 1; i <= k; i++){
        mp[i] = 0;
    }

    for(int i = 0; i < n; i++){
        cin >> w >> l;
        mp[l]++;
    }

    for(auto i : mp){
        if(i.second <= 1){
            cout << i.first << " ";
        }
    }

    return 0;
}