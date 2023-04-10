// DONE

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    map<long long, int> prefixSumCounts;

    long long prefixSum = 0;
    int ans = 0;

    for(int i = 0; i < n; i++){
        prefixSum += arr[i];

        if(prefixSum == (long long)k * (i + 1)){
            ans++;
        }
        if(prefixSumCounts.count(prefixSum - (long long)k * (i + 1))){
            ans += prefixSumCounts[prefixSum - (long long)k * (i + 1)];
        }

        prefixSumCounts[prefixSum - (long long)k * (i + 1)]++;
    }

    cout << ans << endl;
}