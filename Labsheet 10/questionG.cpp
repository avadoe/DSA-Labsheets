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

    vector<int> maxSoFar(n);
    int maxNo = 0;
    for(int i = 0; i < n; i++){
        maxNo = max(maxNo, arr[i]);
        maxSoFar[i] = maxNo;
    }

    for(int i = k - 1; i < n; i++){
        int maxInSubArray = maxSoFar[i];
        if(i - k > 0){
            maxInSubArray = max(maxInSubArray, maxSoFar[i - k]);
        }

        cout << maxInSubArray << " ";
    }
    cout << endl;
}