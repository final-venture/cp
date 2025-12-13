#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
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

int MSS(vector<int>& a, int mode)
{
    int n = a.size();
    int ret = 0;
    int curr = 0;
    for (int i = 0; i < n; ++i)
    {
        if (mode == 1) // maxx
        {
            curr = max(curr + a[i], a[i]);
            ret = max(ret, curr);
        }
        else
        {
            curr = min(curr + a[i], a[i]);
            ret = min(ret, curr);
        }
    }
    return ret;
}

int pfx_MSS(vector<int>& a, int mode)
{
    int n = a.size();
    int curr = 0;
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        if (mode == 1) // maxx
        {
            curr = curr + a[i];
            ret = max(ret, curr);
        }
        else
        {
            curr = curr + a[i];
            ret = min(ret, curr);
        }
    }
    return ret;
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
    int idx = -1; // weird idx
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != -1 && a[i] != 1) idx = i;
    }
    set<int> ret;
    if (idx != -1)
    {
        vector<int> start(a.begin(), a.begin() + idx);
        vector<int> end(a.begin() + idx + 1, a.end());
        int max_s = MSS(start, 1);
        int max_e = MSS(end, 1);
        int min_s = MSS(start, 0);
        int min_e = MSS(end, 0);
        for (int i = min_s; i <= max_s; ++i)
        {
            ret.insert(i);
        }
        for (int i = min_e; i <= max_e; ++i)
        {
            ret.insert(i);
        }

        reverse(all(start));
        int max_sfx = pfx_MSS(start, 1);
        int min_sfx = pfx_MSS(start, 0);
        int max_pfx = pfx_MSS(end, 1);
        int min_pfx = pfx_MSS(end, 0);
        for (int i = min_sfx + min_pfx; i <= max_sfx + max_pfx; ++i)
        {
            ret.insert(i + a[idx]);
        }
    }
    else
    {
        int maxx = MSS(a, 1);
        int minn = MSS(a, 0);
        for (int i = minn; i <= maxx; ++i)
        {
            ret.insert(i);
        }
    }

    cout << ret.size() << '\n';
    for (int x : ret) cout << x << ' ';
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
