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
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    if (a > b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int m = a;
    while (cnt < 2000 && m % b)
    {
        m += a;
        ++cnt;
    }
    cout << m << '\n';
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
