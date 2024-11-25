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
    ll x, m;
    ll res = 0;
    cin >> x >> m;
    for (int y = 1; y <= min(m, 2ll * x); ++y)
    {
        if (x == y) continue;
        if (!(y % (y ^ x)) || !(x % (y ^ x))) ++res;
    }
    cout << res << '\n';
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
