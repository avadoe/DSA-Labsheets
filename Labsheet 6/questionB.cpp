#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans[n];
    for(int i = 0; i < n; i++)
        ans[i] = -1;

    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] < a[i]) {
            int j = s.top();
            s.pop();
            ans[j] = i - j;
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] < a[i]) {
            int j = s.top();
            s.pop();
            ans[j] = n - j + i;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}