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
    ll n, m;
    cin >> n >> m;
    vector<ll> pfx(n, 0);
    ll a[n];
    ll b[m];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    pfx[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        pfx[i] = pfx[i - 1] + a[i];
    }
    vector<ll> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int k = 1; k <= m; ++k)
    {
        ll sum = b[k - 1];
        for (int i = 0; i < n; ++i)
        {
            if (dp[i] == 1e9) continue;
            int idx = upper_bound(all(pfx), sum + (!i ? 0 : pfx[i - 1])) - pfx.begin();
            if (idx == i) continue;
            dp[idx] = min(dp[idx], dp[i] + m - k);
        }
    }
    cout << (dp[n] == 1e9 ? -1 : dp[n]) << '\n';
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
