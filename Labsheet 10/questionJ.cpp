// DONE

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n][n];
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            pq.push(arr[i][j]);
        }
    }

    int t;
    while(!pq.empty() && k){
        t = pq.top();
        pq.pop();
        k--;
    }

    cout << t << endl;
}