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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> aa;
    vector<int> tm; // to move
    for (int i = 0; i < n; ++i)
    {
        while (!aa.empty() && aa.back() > a[i])
        {
            int x = aa.back();
            tm.push_back(x + 1);
            aa.pop_back();
        }
        aa.push_back(a[i]);
    }
    sort(all(tm));
    int tp = 0; // qty to pop from aa
    for (int i = 0; i < aa.size(); ++i)
    {
        if (!tm.empty() && tm.front() < aa[i])
        {
            if (!tp)
                tp = aa.size() - i;
            auto x = aa[i];
            tm.push_back(x + 1);
        }
    }
    for (int i = 0; i < tp; ++i)
    {
        aa.pop_back();
    }
    sort(all(tm));
    vector<int> res;
    for (int i = 0; i < aa.size(); ++i)
    {
        res.pb(aa[i]);
    }

    for (int i = 0; i < tm.size(); ++i)
    {
        res.push_back(tm[i]);
    }
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << ' ';
    }
    cout << '\n';
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
