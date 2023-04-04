#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n; 
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x, y;
    cin >> x >> y;

    unordered_map<int, int> freq;
    int count = 0;

    for(int i = 0; i < n; i++){
        int diff = (a[i] - x * i) - (a[0] - y * 0);
        if(freq.find(diff) != freq.end()){
            count += freq[diff];
        }

        freq[(a[i] - x * i) - (a[0] - y * 0)]++;
    }

    cout << count << endl;
}