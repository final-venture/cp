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

bool check(ll mid, ll t)
{
    if (mid - static_cast<ll>(sqrtl(mid)) >= t)
    {
        return true;
    }
    return false;
}

void solve()
{
    ll t;
    cin >> t;
    ll l = 1;
    ll r = 2e18;
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid, t))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << r << '\n';
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
