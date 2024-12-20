#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
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

const int LOG = 31;

void solve()
{
    int n, q;
    cin >> n >> q;
    int down[n + 1][LOG];
    // down[i][j] represents dest node after 2^j teleports from i
    for (int i = 1; i <= n; ++i)
    {
        cin >> down[i][0];
    }
    for (int i = 1; i < LOG; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            down[j][i] = down[down[j][i - 1]][i - 1];
        }
    }

    // for (int i = 0; i < LOG; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         cout << down[j][i] << ' ';
    //     }
    //     cout << '\n';
    // }

    while (q--)
    {
        int curr, k;
        cin >> curr >> k;
        for (int i = LOG - 1; i >= 0; --i)
        {
            if ((1 << i) & k)
            {
                curr = down[curr][i];
            }
        }
        cout << curr << '\n';
    }
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
