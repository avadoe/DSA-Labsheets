#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> passwords(n);
    for (int i = 0; i < n; i++) {
        cin >> passwords[i];
    }

    unordered_map<string, int> freq_map;
    for (int i = 0; i < n; i++) {
        string sorted_password = passwords[i];
        sort(sorted_password.begin(), sorted_password.end());
        freq_map[sorted_password]++;
    }

    int anagram_pairs = 0;
    for (auto it = freq_map.begin(); it != freq_map.end(); it++) {
        int count = it->second;
        anagram_pairs += count * (count - 1) / 2;
    }

    cout << anagram_pairs << endl;

    return 0;
}
