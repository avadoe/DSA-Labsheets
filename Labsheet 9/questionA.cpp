// WRONG

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int happiness = 0, ans = 0;

    int left = 0, right = 0;

    while(right < n){
        happiness += arr[right];
        while(happiness < 0){
            happiness -= arr[left];
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }

    cout << ans << endl;
    return 0;
}