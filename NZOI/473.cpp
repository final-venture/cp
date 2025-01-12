#include <bits/stdc++.h>

using namespace std;
#define EPS 1e-14
#define ll long long
#define long double

struct Point
{
    double x, y;
};

double cp(Point& A, Point& B, Point& C, Point& D)
{
    Point AB = {B.x - A.x, B.y - A.y};
    Point CD = {D.x - C.x, D.y - C.y};
    return (AB.x * CD.y - AB.y * CD.x);
}

int check(pair<Point, Point>& l1, pair<Point, Point>& l2) {
    double cp1 = cp(l1.first, l1.second, l1.first, l2.first);
    double cp2 = cp(l1.first, l1.second, l1.first, l2.second);
    double cp3 = cp(l2.first, l2.second, l2.first, l1.first);
    double cp4 = cp(l2.first, l2.second, l2.first, l1.second);

    if (abs(cp1) <= EPS && abs(cp2) <= EPS && abs(cp3) <= EPS && abs(cp4) <= EPS) 
    {
        return 2; // Collinear
    } else if (cp1 * cp2 < 0 && cp3 * cp4 < 0) 
    {
        return 1; // Intersecting
    } else 
    {
        return 0; // Not intersecting
    }
}

bool check2(pair<Point, Point>& l1, pair<Point, Point>& l2)
{
    vector<Point> points {l1.first, l1.second, l2.first, l2.second};
    vector<double> yc {points[0].y, points[1].y, points[2].y, points[3].y};
    vector<double> xc {points[0].x, points[1].x, points[2].x, points[3].x};
    if (abs(l1.first.x - l2.first.x) <= EPS) // vertical, do a y check
    {
        sort(yc.begin(), yc.end());
        if (abs(yc[1] - yc[2]) <= EPS) return true;
    }
    else // non-vertical, do an x check
    {
        sort(xc.begin(), xc.end());
        if (abs(xc[1] - xc[2]) <= EPS) return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<Point, Point>> a(n);
    for (int i = 0; i < n; ++i)
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {{x1, y1}, {x2, y2}};
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int res = check(a[i], a[j]);
            if (res == 1)
            {
                ++cnt;
            }
            else if (res == 2)
            {
                // cout << "test" << endl;
                if (check2(a[i], a[j]))
                {
                    // cout << "test2" << endl;
                    ++cnt;
                }
            }
        }
    }
    cout << cnt;
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
