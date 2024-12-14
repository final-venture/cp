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
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int maxx = accumulate(all(a), 0) + 10;
    vector<int> dp(maxx, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = maxx - 1; j >= 0; --j)
        {
            if (a[i] <= j)
            {
                dp[j] |= dp[j - a[i]];
            }
        }
    }
    // for (int i = 0; i < maxx; ++i)
    // {
    //     cout << dp[i] << ' ';
    // }
    vector<int> resvec;
    for (int i = 1; i < maxx; ++i)
    {
        if (dp[i]) resvec.pb(i);
    }
    cout << resvec.size() << '\n';
    for (int x : resvec)
    {
        cout << x << ' ';
    }
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
