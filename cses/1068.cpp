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
    ll n;
    cin >> n;
    vector<ll> ret;
    while (n != 1)
    {
        ret.pb(n);
        if (n & 1)
        {
            n *= 3;
            ++n;
        }
        else n /= 2;
    }
    ret.pb(1);
    for (ll x : ret) cout << x << ' ';
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
