// DONE

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int left = 0, right = 1, ans = 0;

    while(right < n){
        if(arr[right] - arr[left] >= k){
            ans++;
            left++;
            right++;
        }else{
            right++;
        }
    }

    cout << ans << endl;
}