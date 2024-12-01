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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<ll> dp(n);
    dp[0] = n - 1;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = dp[i - 1] - i + (n - 1 - i);
    }
    vector<ll> dp2(n);
    dp2[0] = n - 1;
    int expire = 0;
    for (int i = 1; i < n; ++i)
    {
        dp2[i] = (n - 1 - i) + dp2[i - 1] - expire;
        ++expire;
    }
    map<ll, ll> q2r;
    for (int i = 0; i < n - 1; ++i)
    {
        q2r[dp[i]] += (a[i + 1] - a[i] - 1);
    }
    for (int i = 0; i < n; ++i)
    {
        ++q2r[dp2[i]];
    }
    for (int i = 0; i < q; ++i)
    {
        ll x;
        cin >> x;
        if (q2r.find(x) == q2r.end())
        {
            cout << 0 << ' ';
            continue;
        }
        cout << q2r[x] << ' ';
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
