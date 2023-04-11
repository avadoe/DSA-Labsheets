#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> prefixSum(n + 1);
    map<int, int> freq;
    freq[0] = 1;
    int ans = 0;

    for(int i = 1; i <= n; i++){
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        ans += freq[prefixSum[i] - k * i];
        freq[prefixSum[i] - k * i]++;
    }

    cout << ans << endl;
}