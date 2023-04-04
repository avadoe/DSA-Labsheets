#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for(int i = 0; i < q; i++){
        int type, k;

        cin >> type >> k;

        if(type == 1){
            a[k - 1] = 1 - a[k - 1];
        }
        else if(type == 2){
            auto it = find(a.begin() + k - 1, a.end(), 1);
            if(it != a.end()){
                cout << distance(a.begin(), it) + 1 << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        else{
            auto rit = find(a.rbegin() + (n - k), a.rend(), 1);
            if (rit != a.rend()) {
                cout << n - distance(a.rbegin(), rit) << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
}