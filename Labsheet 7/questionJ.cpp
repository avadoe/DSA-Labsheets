#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> A(n), B(n);

    for(int i = 0; i < n; i++)
        cin >> A[i];

    for(int i = 0; i < n; i++)
        cin >> B[i];

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        pq.push(A[0] + B[i]);
    }
    for(int i = 0; i < n; i++){
        pq.push(A[1] + B[i]);
    }

    for(int i = 0; i < k; i++){
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;

    return 0;
}