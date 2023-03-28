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

    int left = 0, right = 0, count = 0, ans = 0;

    while(right < n){
        if(arr[right] == 1){
            count++;
        }

        while(count > k){
            if(arr[left] == 1){
                count--;
            }
            left++;
        }

        ans += right - left + 1;

        right++;
    }

    cout << ans << endl;
    return 0;
}