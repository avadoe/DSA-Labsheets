// DONE

#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
    int current = 0, total = 0;
    int diff = 0, start = 0;

    for(int i = 0; i < gas.size(); i++){
        diff = gas[i] - cost[i];

        total += diff;
        current += diff;

        if(current < 0){
            start = i + 1;
            current = 0;
        }
    }

    if(total >= 0){
        return start;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b(n);
    for(int i = 0; i < n; i++)
        cin >> b[i];

    int ans = canCompleteCircuit(a, b);

    cout << ans << endl;
}   