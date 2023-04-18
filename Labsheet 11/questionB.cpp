// DONE

#include <iostream>
#include <vector>
using namespace std;
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

    int s1 = 0, ins1 = 0, s2 = 0;
    int longest = INT_MIN, currLen = 0;

    while(s1 < n){
        for(int s2 = 0; s2 < m; s2++){
            if(a[s1] == b[s2]){
                s1++;
                currLen++;
            }
            longest = max(currLen, longest);
        }
        currLen = 0;
        ins1++;
        s1 = ins1;
    }

    cout << longest << endl;
}