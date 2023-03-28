#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    priority_queue<int> pq;

    for(int i = 0; i < n; i++)
        pq.push(v[i]);

    while(m){
        int x = pq.top();
        pq.pop();
        x /= 2;
        pq.push(x);
        m--;
    }

    int cost = 0;

    while(!pq.empty()){
        cost += pq.top();
        pq.pop();
    }

    cout << cost << endl;
}