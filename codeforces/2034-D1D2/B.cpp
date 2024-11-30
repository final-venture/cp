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
    int n, m, k;
    string s;
    cin >> n >> m >> k;
    cin >> s;
    int cnt = 0;
    int i = 0;
    int res = 0;
    while (i < n)
    {
        if (s[i] == '0')
        {
            ++cnt;
            ++i;
        }
        else
        {
            cnt = 0;
            ++i;
        }
        if (cnt >= m)
        {
            ++res;
            i += k - 1;
            cnt = 0;
        }
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
