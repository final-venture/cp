#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
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

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 1 || k > n)
    {
        cout << n << '\n';
        return;
    }
    int res = 0;
    res += n % k;
    n -= (n % k);
    while (n)
    {
        int cand = k;
        while (cand * k <= n)
        {
            cand = cand * k;
        }
        ++res;
        n -= cand;
    }
    cout << res << '\n';
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
