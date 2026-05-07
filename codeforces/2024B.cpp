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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll subby = 0;
    ll res = 0;
    ll cnt = 0;
    for (ll i = 0; i < n;)
    {
        if (a[i] == subby)
        {
            ++i;
            ++res;
            continue;
        }
        cnt += (n - i) * (a[i] - subby);
        subby = a[i];
        if (k <= cnt)
        {
            res += k;
            break;
        }
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
