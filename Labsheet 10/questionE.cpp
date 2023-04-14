// DONE

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<pair<int, int> > arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.rbegin(), arr.rend());

    stack<pair<int, int> > st;
    st.push(arr[0]);

    int longestSeq = 1;
    for(int i = 1; i < n; i++){
        if(arr[i].first < st.top().first && arr[i].second < st.top().second){
            st.push(arr[i]);
            longestSeq++;
        }
        else{
            while(arr[i].first >= st.top().first && arr[i].second >= st.top().second){
                st.pop();
                longestSeq--;
            }
        }
    }

    cout << longestSeq << endl;
}