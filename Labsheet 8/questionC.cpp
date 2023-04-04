// WRONG

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int x, y;
    cin >> x >> y;

    unordered_map<int, int> freq;
    int ans = 0;

    for(int j = 0; j < n; j++){
        freq[y * j - arr[j]]++;
    }

    for(auto x : freq){
        int y = x.second;
        ans += y * (y - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}
