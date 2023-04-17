// WRONG

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    unordered_map<int, int> freq;

    for(int i = 0; i < n; i++){
        freq[a[i]]++;
    }

    queue<int> q;
    vector<int> ans;
    for(int i = 0; i < m; i++){
        if(freq[b[i]] != 0){
            while(freq[b[i]]){
                ans.push_back(b[i]);
                freq[b[i]]--;
            }
        }else{
            q.push(b[i]);
        }
    }

    vector<int> test;
    while(!q.empty()){
        test.push_back(q.front());
        q.pop();
    }

    sort(test.begin(), test.end());
    for(int i = 0; i < test.size(); i++){
        ans.push_back(test[i]);
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    cout << "\n";
    return 0;
}