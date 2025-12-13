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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(all(a), greater<int>());
    for (int i = 0; i < n; ++i)
    {
        if (k - a[i] < 0)
        {
            break;
        }
        k -= a[i];
    }
    cout << k << '\n';
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
