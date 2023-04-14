// DONE

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> mp;

    int count = 0;

    for(int i = 0; i < n; i++){
        auto it = mp.upper_bound(arr[i]);
        while(it != mp.end()){
            count += it->second;
            it++;
        }
        mp[arr[i]]++;
    }
    cout << count << endl;
}