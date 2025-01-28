#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define MOD 998244353
#define int ll

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> ofreq;
    set<int> o;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++ofreq[x];
        o.insert(x);
    }
    map<int, int> tfreq;
    set<int> t;
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        ++tfreq[x];
        t.insert(x);
    }
    while (true)
    {
        if (o.empty() && t.empty())
        {
            cout << "YES" << '\n';
            return;
        }
        if (t.empty() || o.empty())
        {
            cout << "NO" << '\n';
            return;
        }
        int mxo = *o.rbegin();
        int mxt = *t.rbegin();
        if (mxo > mxt)
        {
            cout << "NO" << '\n';
            return;
        }
        else if (tfreq[mxo])
        {
            --ofreq[mxo];
            --tfreq[mxo];
            if (!ofreq[mxo])
                o.erase(mxo);
            if (!tfreq[mxo])
                t.erase(mxo);
        }
        else
        {
            t.insert(mxt / 2);
            tfreq[mxt / 2] += tfreq[mxt];
            t.insert((mxt + 1) / 2);
            tfreq[(mxt + 1) / 2] += tfreq[mxt];
            tfreq[mxt] = 0;
            if (!tfreq[mxt])
                t.erase(mxt);
        }
        // for (int x : t)
        //     cout << x << ' ';
        // cout << '\n';
    }
    cout << 0 / 0 << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
