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
    vector<int> res(n, 0);
    vector<pair<int, pair<int, int>>> se(n);
    vector<pair<int, pair<int, int>>> ee(n);
    vector<int> ok(n, 0);
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        se[i] = {l, {r, i}};
        ee[i] = {r, {l, i}};
    }
    multiset<int> ends;
    sort(all(se));
    for (int i = 0; i < n; ++i)
    {
        if (!ok[i])
        {
            ends.insert(se[i].second.first);
            ok[i] = 1;
            for (int j = i + 1; j < n; ++j)
            {
                if (se[i].first == se[j].first)
                {
                    ends.insert(se[j].second.first);
                    ok[j] = 1;
                }
                else
                {
                    break;
                }
            }
        }
        auto it = ends.lower_bound(se[i].second.first);
        auto it2 = next(it);
        if (it2 != ends.end())
        {
            res[se[i].second.second] += (*it2 - se[i].second.first);
        }
    }

    ok = vector<int>(n, 0);
    multiset<int> starts;
    sort(all(ee), greater<void>());
    for (int i = 0; i < n; ++i)
    {
        if (!ok[i])
        {
            starts.insert(ee[i].second.first);
            ok[i] = 1;
            for (int j = i + 1; j < n; ++j)
            {
                if (ee[i].first == ee[j].first)
                {
                    starts.insert(ee[j].second.first);
                    ok[j] = 1;
                }
                else
                {
                    break;
                }
            }
        }
        auto it = starts.upper_bound(ee[i].second.first);
        auto it2 = prev(it);
        if (it2 == starts.begin()) continue;
        auto it3 = prev(it2);
        res[ee[i].second.second] += (ee[i].second.first - *it3);
    }
    for (int x : res)
    {
        cout << x << '\n';
    }
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
