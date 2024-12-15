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

ll dp[20][11][2][2];
ll solve2(string& num, int n, int prevd, bool leading, bool tight)
{
    if (!n) return 1;
    if (dp[n][prevd][leading][tight] != -1) return dp[n][prevd][leading][tight];
    int stdd = num[num.size() - n] - '0';
    int ub = tight ? stdd : 9;

    ll ret = 0;
    for (int d = 0; d <= ub; ++d)
    {
        if (d == prevd && !leading) continue;
        ret += solve2(num, n - 1, d, (leading && (d == 0)), (tight && (d == stdd)));
    }

    return dp[n][prevd][leading][tight] = ret;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    string A = to_string(a - 1);
    string B = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll big = solve2(B, B.size(), 0, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll small = solve2(A, A.size(), 0, 1, 1);
    cout << big - small << '\n';
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
