#include <bits/stdc++.h>

using namespace std;

struct Point 
{
    int x, y;
};

int cross_product(Point a, Point b, Point c) 
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() 
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    Point p;
    cin >> p.x >> p.y;

    int n;
    cin >> n;

    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> polygon[i].x >> polygon[i].y;
    }

    bool on_boundary = false;
    int winding_number = 0;

    for (int i = 0; i < n; ++i) 
    {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];

        if (cross_product(p1, p2, p) == 0) 
        {
            if (min(p1.x, p2.x) <= p.x && p.x <= max(p1.x, p2.x) &&
                min(p1.y, p2.y) <= p.y && p.y <= max(p1.y, p2.y)) 
                {
                on_boundary = true;
                break;
            }
        }

        if (p1.y <= p.y) 
        {
            if (p2.y > p.y && cross_product(p1, p2, p) > 0) 
            {
                winding_number++;
            }
        } else 
        {
            if (p2.y <= p.y && cross_product(p1, p2, p) < 0) 
            {
                winding_number--;
            }
        }
    }

    if (on_boundary) 
    {
        cout << "BOUNDARY";
    } else if (winding_number != 0) 
    {
        cout << "INSIDE";
    } else 
    {
        cout << "OUTSIDE";
    }

    return 0;
}
