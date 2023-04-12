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

    int presentMax = arr[0], presentMaxIdx = 0, presentMin = arr[0], presentMinIdx = 0;

    int left = 0, right = 1, sum = 0;

    while(right <= n){
        if(right == n){
            sum += (right - left) * (presentMax - presentMin);
            left++;
        }
        else if(arr[right] >= presentMax){
            presentMax = arr[right];
            presentMaxIdx = right;
        }
        else if(arr[right] <= presentMin){
            presentMin = arr[right];
            presentMinIdx = right;
        }
        else{
            sum += (right - left) * (presentMax - presentMin);
            left = presentMinIdx + 1;
            presentMax = arr[right];
            presentMaxIdx = right;
            presentMin = arr[right];
            presentMinIdx = right;
        }
        right++;
    }

    cout << sum << endl;
}
