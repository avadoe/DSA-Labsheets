#include <iostream>
#include <vector>
using namespace std;

struct Point{
    int x, y;
};

bool cmp(Point a, Point b){
    return a.x < b.x;
}

int main()
{
    int n;
    cin >> n;

    vector<Point> points(n);

    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), cmp);

    for(int i = 0; i < n; i++)
        cout << points[i].x << " " << points[i].y << endl;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double slope = (double)((points[j].y - points[i].y)/(points[j].x - points[i].x));

            vector<double> slopes;

            for(int k = j + 1; k < n; k++){
                
            }
        }
    }
}