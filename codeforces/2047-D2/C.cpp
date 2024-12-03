#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define int ll

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
    vector<int> row1(n);
    vector<int> row2(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> row1[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> row2[i];
    }
    vector<int> st(n); // which row is bigger
    for (int i = 0; i < n; ++i)
    {
        if (row1[i] >= row2[i])
        {
            st[i] = 0;
        }
        else
        {
            st[i] = 1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!st[i])
        {
            res += row1[i];
        }
        else
        {
            res += row2[i];
        }
    }
    int maxx = -1e6;
    for (int i = 0; i < n; ++i)
    {
        if (!st[i])
        {
            maxx = max(maxx, row2[i]);
        }
        else
        {
            maxx = max(maxx, row1[i]);
        }
    }
    res += maxx;
    cout << res << '\n';
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
