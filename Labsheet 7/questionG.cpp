#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    priority_queue<int> pq;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        pq.push(v[i]);
    }

    int ans = 0;

    while(k){
        int x = pq.top();
        pq.pop();
        int y = (x + 1)/2;
        ans += y;
        pq.push(x - y);
        k--;
    }

    cout<<ans<<endl;
}