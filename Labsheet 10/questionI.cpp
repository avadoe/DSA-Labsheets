// DONE

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(m);

    int sumA = 0, sumB = 0;

    for(int i = 0; i < n; i++){
        cin >> A[i];
        sumA += A[i];
    }

    for(int i = 0; i < m; i++){
        cin >> B[i];
        sumB += B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int diff;

    if(sumA > sumB){
        diff = sumA - sumB;
    }else{
        diff = sumB - sumA;
    }

    if(diff % 2 != 0){
        cout << "NO\n";
        return 0;
    }

    int r, l;

    int t = diff / 2;

    if(sumA > sumB){
        r = 0, l = 0;
        while(l < m && r < n){
            int curr_diff = A[r] - B[l];
            if(curr_diff == t || curr_diff == -t){
                cout << "YES\n";
                return 0;
            }else if(curr_diff < t){
                l++;
            }else{
                r--;
            }
        }
    }else{
        r = 0, l = 0;
        while(l < m && r < n){
            int curr_diff = B[l] - A[r];
            if(curr_diff == t || curr_diff == -t){
                cout << "YES\n";
                return 0;
            }else if(curr_diff < t){
                l++;
            }else{
                r++;
            }
        }
    }
}