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
    if (n == 1)
    {
        cout << 1;
        return;
    }
    else if (n < 4)
    {
        cout << "NO SOLUTION" << '\n';
        return;
    }
    int curr = n;
    vector<int> ret(n);
    for (int i = 1; i < n; i += 2)
    {
        ret[i] = curr--;
    }
    for (int i = 0; i < n; i += 2)
    {
        ret[i] = curr--;
    }
    for (int x : ret) cout << x << ' ';
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
