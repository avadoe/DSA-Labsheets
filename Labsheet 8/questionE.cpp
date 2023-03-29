#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> counts;
    int l = 0, r = 0;

    while(r < m){
        counts[arr[r]]++;
        r++;
    }

    vector<int> ans(n - m + 1);

    for(int i = 0; i < n - m + 1; i++){
        if(i){
            counts[arr[l]]--;
            l++;
            counts[arr[r]]++;
            r++;
        }
        int max_occ = -1;

        for(auto p : counts){
            if(p.second == k){
                max_occ = max(max_occ, p.first);
            }
        }
        ans[i] = max_occ;
    }

    for(int i = 0; i < n - m + 1; i++)
        cout << ans[i] << " ";

    cout << endl;
    return 0;
}