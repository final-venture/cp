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
    int n;
    cin >> n;
    // cout << "XD?" << '\n';
    vector<int> seen(n + 1, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        int x;
        cin >> x;
        seen[x] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!seen[i])
        {
            cout << i << '\n';
            return;
        }
    }
    // cout << -1 << '\n';
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
