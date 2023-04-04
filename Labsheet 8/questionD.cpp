// WRONG

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    long long n, q;
    cin >> n >> q;

    vector<long long> arr(n);

    while(q--){
        long long type, k;
        cin >> type >> k;

        if(type == 1){
            arr[k - 1] ^= 1;
        }

        else if(type == 2){
            long long ans = -1;

            for(long long i = k - 1; i < n; i++){
                if(arr[i] == 1){
                    ans = i + 1;
                    break;
                }
            }

            cout << ans << endl;
        }

        else{
            long long ans = -1;

            for(long long i = k - 1; i >= 0; i--){
                if(arr[i] == 1){
                    ans = i + 1;
                    break;
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}