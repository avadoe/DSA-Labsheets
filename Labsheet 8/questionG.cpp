#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<pair<int, int> > points(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        points[i].first = a;
        points[i].second = b;
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        float x1 = points[i].first;
        float y1 = points[i].second;

        int same_X_coor_slope = 0;
        map<float, int> mp;

        for(int j = i + 1; j < n; j++){
            float x2 = points[j].first;
            float y2 = points[j].second;

            if(x1 == x2){
                same_X_coor_slope++;
            }
            else{
                mp[(y2 - y1) / (x2 - x1)]++;
            }
        }

        float sum_square = same_X_coor_slope * same_X_coor_slope;
        float sum_total = same_X_coor_slope;

        for(auto x : mp){
            sum_square += x.second * x.second;
            sum_total += x.second;
        }

        sum_total *= sum_total;
        ans += (sum_total - sum_square) / 2;
    }

    cout << ans << endl;
}