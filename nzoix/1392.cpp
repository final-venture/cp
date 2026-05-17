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

void solve()
{
    int n, a;
    cin >> n >> a;
    map<int, vector<pair<int, int>>> ri;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        int s = max(0ll, x - a);
        int e = x + a;
        for (int i = s; i <= e; ++i)
        {
            ri[i].push_back({max(0ll, y - a), y + a}); //intervals inclusive
        }
    }
    int res = 0;
    for (auto& [x, y] : ri)
    {
        vector<pair<int, int>> cand;
        sort(all(y));
        for (int i = 0; i < y.size(); ++i)
        {
            int nn = cand.size();
            if (nn && y[i].first <= cand[nn - 1].second)
            {
                cand[nn - 1] = {min(cand[nn - 1].first, y[i].first), max(cand[nn - 1].second, y[i].second)};
            }
            else
            {
                cand.push_back(y[i]);
            }
        }
        for (auto& [l, r] : cand)
        {
            res += (r - l + 1);
        }
    }
    cout << res << '\n';
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
