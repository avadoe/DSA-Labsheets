// WRONG

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
        sum -= b[i];
    }

    if(sum % 2 != 0){
        cout << "NO\n";
        return 0;
    }

    unordered_map<int, int> freq;
    int target = sum / 2;

    for(int i = 0; i < n; i++){
        freq[a[i]]++;
    }

    for(int i = 0; i < m; i++){
        int diff = b[i] - target;

        if(freq[diff] > 0){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}