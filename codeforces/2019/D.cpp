#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, set<int>> n2i; // can use vpii here to store {minidx, maxidx} for each number
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        n2i[a[i]].insert(i);
    }
    int minn = n;
    int maxx = 0;
    for (int t = 1; t < n + 1; ++t)
    {
        if (n2i.find(t) == n2i.end())
        {
            continue;
        }
        int x = *n2i[t].begin();
        int y = *n2i[t].rbegin();
        minn = min(minn, x);
        maxx = max(maxx, y);
        // cout << t << ' ' << y << ' ' << x << '\n';
        if (maxx - minn + 1 > t)
        {
            cout << 0 << '\n';
            return;
        }
    }
    int l = 0;
    int r = n - 1;
    for (int i = 0; i < n; ++i)
    {
        l = max(l, i - a[i] + 1);
        r = min(r, i + a[i] - 1);
    }
    cout << r - l + 1 << '\n';
}

signed main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
