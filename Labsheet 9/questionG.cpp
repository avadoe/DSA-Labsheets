// DONE

#include <iostream>
#include <vector>
using namespace std;

bool compareString(string a, string b){
    return (a + b) > (b + a);
}

int main()
{
    int n;
    cin >> n;

    vector<string> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end(), compareString);

    string ans = "";
    
    for(int i = 0; i < n; i++){
        ans += arr[i];
    }

    cout << ans << endl;
}