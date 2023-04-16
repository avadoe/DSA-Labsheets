// WRONG

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    unordered_map<int, int> a_count;
    unordered_map<int, int> positions;

    for(int i = 0; i < m; i++)
        positions[b[i]] = i;

    for(int i = 0; i < n; i++)
        a_count[a[i]]++;

    vector<int> ans(n);

    int start = 0;
    for(int i = 0; i < m; i++){  
        if(a_count[b[i]]){
            while(a_count[b[i]]){
                ans.push_back(b[i]);
                a_count[b[i]]--;
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << "\n";
    return 0;
}