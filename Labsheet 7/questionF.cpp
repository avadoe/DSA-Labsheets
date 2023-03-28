#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int k;
    cin>>k;

    int x;

    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 0; i < k; i++){
        cin >> x;
        vector<int> v(x);

        for(int i = 0; i < x; i++){
            cin>>v[i];
            pq.push(v[i]);
        }
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    cout<<endl;
    return 0;
}