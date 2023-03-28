#include <iostream>
#include <stack>
using namespace std;

// ai number of students score exactly i marks
// marks range from 1 to n
// ai => height of each bar

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    stack<int> st;
    int i = 0;
    int maxArea = 0;

    while(i < n || !st.empty()){
        if(st.empty() || (i < n && arr[st.top()] <= arr[i])){
            st.push(i);
            i++;
        }else{
            int j = st.top();
            st.pop();

            int h = arr[j];
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
    }

    cout << maxArea << endl;
    return 0;
}