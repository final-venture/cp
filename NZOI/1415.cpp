#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define int ll

#define LOCAL

void init()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int getDist(pair<int, int> p1, pair<int, int> p2)
{
    auto& [x1, y1] = p1;
    auto& [x2, y2] = p2;
    double e1 = (x1 - x2) * (x1 - x2);
    double e2 = (y1 - y2) * (y1 - y2);
    return ceil(sqrt(e1 + e2));
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pts(n);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }
    vector<int> stops(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> stops[i];
    }
    vector<int> money(m, 0);
    for (int i = m - 2; i >= 0; --i)
    {
        money[i] = money[i + 1] + getDist(pts[stops[i]], pts[stops[i + 1]]);
    }
    vector<int> subby(m, 0);
    for (auto& p : pts)
    {
        int l = 0;
        int r = m - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (getDist(p, pts[stops[m]]) <= money[m]) // not satisfy - REVIEW why <=
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        ++subby[l];
    }
    int res = n - 1;
    for (int i = 0; i < m; ++i)
    {
        res -= subby[i];
        cout << ((res < 0) ? 0 : res) << ' ';
    }
#ifdef LOCAL
    cout << '\n';
#endif
}

signed main()
{
    init();
#ifdef LOCAL
    int t;
    cin >> t;
    while (t--)
#endif
        solve();
    return 0;
}
