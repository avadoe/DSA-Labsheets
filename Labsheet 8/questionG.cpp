#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

bool cmp(Point a, Point b) {
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), cmp);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[i].x == points[j].x) {
                continue;
            }

            double slope = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);

            vector<double> slopes;
            for (int k = j + 1; k < n; k++) {
                if (points[k].x == points[j].x) {
                    continue;
                }
                double s = (double)(points[k].y - points[i].y) / (points[k].x - points[i].x);
                slopes.push_back(s);
            }

            sort(slopes.begin(), slopes.end());

            int cnt = 1;
            for (int k = 1; k < slopes.size(); k++) {
                if (slopes[k] == slopes[k - 1]) {
                    cnt++;
                } else {
                    ans += cnt * (cnt - 1) / 2;
                    cnt = 1;
                }
            }
            ans += cnt * (cnt - 1) / 2;
        }
    }

    int collinear = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((points[j].y - points[i].y) * (points[k].x - points[j].x) == 
                    (points[k].y - points[j].y) * (points[j].x - points[i].x)) {
                    collinear++;
                }
            }
        }
    }

    int triangles = n * (n - 1) * (n - 2) / 6 - collinear;
    cout << triangles - ans << endl;

    return 0;
}
