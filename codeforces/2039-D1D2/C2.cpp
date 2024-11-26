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

// let z = x ^ y
// then we can see z ^ x = y
void solve()
{
    int x;
    ll m;
    cin >> x;
    cin >> m;
    ll res = 0;
    for (int y = 1; y < 2 * x && y <= m; ++y) // brute divisors from 1 <= z <= 2x - 1
    {
        int z = x ^ y;
        if (z < 2 * x && (!(z % x) || !(z % y))) ++res;
    }
    if (m - x >= 2 * x) // count divisors from 2x <= z <= m - x
    {
        res += (m - x) / x - (2 * x - 1) / x;
    }
    for (ll z = max(2ll * x, m - x + 1); z <= m + x; ++z) // count divisors from m - x + 1 <= z <= m + x
    {
        if (z % x) continue;
        ll y = z ^ x;
        if (y >= 1 && y <= m) ++res;
    }
    cout << res << '\n';
}

// void xd()
// {
//     int x = 1000;
//     for (int i = 1; i < x; ++i)
//     {
//         int xord = i ^ 5;
//         cout << xord << endl;
//     }
// }

int main()
{
    init();
    // xd();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
