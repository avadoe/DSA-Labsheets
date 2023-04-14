// DONE

#include <iostream>
#include <vector>
using namespace std;

float medianOfSortedArrays(vector<int>& a, vector<int>& b){
    int temp = 0, l = 0, r = 0;
    int n = a.size(), m = b.size();

    vector<int> comb(m + n);

    while(temp < m + n){
        if(l < n && r < m){
            if(a[l] < b[r]){
                comb[temp] = a[l];
                l++;
            }
            else{
                comb[temp] = b[r];
                r++;
            }
        }
        else if(l < n){
            comb[temp] = a[l];
            l++;
        }
        else if(r < m){
            comb[temp] = b[r];
            r++;
        }
        else{
            break;
        }
        temp++;
    }

    int medianIdx1 = (m + n - 1) / 2;
    int medianIdx2 = (m + n) / 2;
    if((m + n)%2 == 0){
        float sum = comb[medianIdx1] + comb[medianIdx2];
        return sum / 2.0;
    }
    return comb[medianIdx1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;
    
    vector<int> b(m);
    for(int i = 0; i < m; i++)
        cin >> b[i];

    float ans = medianOfSortedArrays(a, b);
    cout << ans << endl;
    return 0;
}