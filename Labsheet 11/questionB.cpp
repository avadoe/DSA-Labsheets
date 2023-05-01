#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    int currLen = 0, longest = INT_MIN;
    int travL = 0;
    int l = 0, r = 0;

    while(l < n){
        for(int r = 0; r < m; r++){
            if(a[l] == b[r]){
                l++;
                currLen++;
            }
            longest = max(currLen, longest);
        }
        currLen = 0;
        travL++;
        l = travL;
    }

    cout << longest << endl;    
}