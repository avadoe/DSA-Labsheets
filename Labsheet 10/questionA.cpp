// DONE

#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int>& arr){
    int ans = arr[0], sum = 0;
    int r = 0, n = arr.size();

    while(r < n){
        sum += arr[r];
        ans = max(ans, sum);
        sum = max(sum, 0);
        r++;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxSubarraySum(arr) << endl;
}