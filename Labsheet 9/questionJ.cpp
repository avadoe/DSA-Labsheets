// DONE

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int arrival, departure;
        cin >> arrival >> departure;
        mp[arrival]++;
        mp[departure]--;
    }

    int trains = 0, platforms = 0;
    for (auto& event : mp) {
        trains += event.second;
        platforms = max(platforms, trains);
    }

    cout << platforms << endl;

    return 0;
}
