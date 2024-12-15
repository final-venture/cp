#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define MOD 1000000007

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int n, m;
vector<vector<int>> dp;
// m + 1 because we need to propagate when we reach col m and bit n (beyond last row)

void dfs(int col, int bit, int cmask, int nmask)
{
    if (bit == n) // if we reached beyond last row of each column
    {
        // if we ever make a certain nmask, we add qty of ways to make cmask - results in:
        //   dp[col + 1][nmask] = qty of ways to make cmask * ways we can make nmask from cmask
        dp[col + 1][nmask] += dp[col][cmask];
        dp[col + 1][nmask] %= MOD;
        return;
    }
    if (cmask & (1 << bit))
    {
        // go straight onto next bit
        dfs(col, bit + 1, cmask, nmask);
    }
    else
    {
        // WE NEVER SIMULATE CHANGES IN CMASK BECAUSE WE WANT QTY OF WAYS FROM ORIGINAL CMASK

        // we can always put a 2x1 block horizontally
        //  because we're returning dp[m][0] - nothing filled beyond the last column
        dfs(col, bit + 1, cmask, nmask | (1 << bit));
        // if we have 2x1 unfilled space we can place 1x2 block vertically
        if (bit + 1 < n && !(cmask & (1 << (bit + 1))))
        {
            dfs(col, bit + 2, cmask, nmask);
        }
    }
}

void solve()
{
    cin >> n >> m;
    dp.resize(m + 1, vector<int>(1 << n, 0));
    // dp[i][j] is the amount of valid ways to fill from 0th to (i - 1)th column with j
    //   already filled in the (i - 1)th column
    dp[0][0] = 1;
    for (int col = 0; col < m; ++col)
    {
        // we will have processed if it's popssible to make all masks in the current column,
        //   because each dfs call updates next column's dp values
        for (int mask = 0; mask < (1 << n); ++mask)
        {
            if (dp[col][mask] > 0) // if it's possible to make this mask and have all
                //   previous elements filled
            {
                dfs(col, 0, mask, 0);
            }
        }
    }
    // for (int i = 0; i < m + 1; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[m][0] << '\n';
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
