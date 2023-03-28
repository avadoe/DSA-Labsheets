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

    unordered_map<int, int> mp;

    mp[0] = 1;

    int prefix_xor = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        prefix_xor ^= arr[i];
        count += mp[prefix_xor];
        mp[prefix_xor]++;
    }

    cout << count << endl;
}