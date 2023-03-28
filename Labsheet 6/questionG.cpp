// Push the indices of the elements into the stack, rather than the numbers themselves, 
// Allows for us to not have the need to store the indices again

#include <iostream>
#include <stack>
using namespace std;

void getStockSpread(int arr[], int n){
    int newArr[n];
    newArr[0] = 1;

    stack<int> st;
    st.push(0);

    for(int i = 1; i < n; i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
            st.pop();
        }
        newArr[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    for(int i = 0; i < n; i++)
        cout<<newArr[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    getStockSpread(arr, n);
    return 0;
}