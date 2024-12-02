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
    vector<int> res(1005, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    map<int, int> n2c;
    for (int i = 0; i < n; ++i)
    {
        ++n2c[a[i]];
    }
    vector<pair<int, int>> c2n;
    for (auto& [n, c] : n2c)
    {
        c2n.push_back({c, n});
    }
    sort(all(c2n));
    int ok = 1;
    int i = 0;
    vector<pair<int, int>> c2n2(all(c2n));
    int n2 = c2n.size();
    while (i < n2)
    {
        if (!c2n[i].first)
        {
            ++i;
            continue;
        }
        if (ok)
        {
            if (c2n2[i].first == 1) res[c2n[i].second] = 2;
            else res[c2n[i].second] = 1;;
        }
        ok = !ok;
        --c2n[i].first;
    }
    int ress = accumulate(all(res), 0);
    cout << ress << '\n';
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
