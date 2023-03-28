#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    int w, l;

    unordered_map<int, int> mp;

    for(int i = 1; i <= k; i++){
        mp[i] = 0;
    }

    for(int i = 0; i < n; i++){
        cin >> w >> l;

        mp[l]++;
    }

    for(int i = 1; i <= k; i++){
        if(mp[i] <= 1){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}