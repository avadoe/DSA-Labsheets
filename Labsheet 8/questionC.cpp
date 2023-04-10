#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int x, y;
    cin >> x >> y;

    unordered_map<int, int> mp;

    int ans = 0;

    for(int i = 0; i < n; i++){
        int diff = arr[i] - y * i;
        if(mp.count(diff)){
            ans += mp[diff];
        }
        mp[arr[i] - x * i]++;
    }

    cout << ans << endl;
}