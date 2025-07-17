#include <bits/stdc++.h>

#define int long long
#define MOD 1000000007

using namespace std;

int n, m;
vector<int> weights;
vector<int> profits;

// int dfs(int i, int wt)
// {
//     if (i >= n)
//     {
//         return 0;
//     }
//     if (memo.find(i * (m + 1) + wt) != memo.end())
//     {
//         cout << 2 << endl;
//         return memo[i * (m + 1) + wt];
//     }

//     int take = -1;
//     if (wt + weights[i] <= m)
//     {
//         take = profits[i] + dfs(i + 1, wt + weights[i]);
//     }
//     int notTake = dfs(i + 1, wt);

//     // memo.erase((i + 1) * (m + 1) + wt);
//     // memo.erase((i + 1) * (m + 1) + (wt + weights[i]));

//     return memo[i * (m + 1) + wt] = max(take, notTake);
// }

void solve()
{
    cin >> n >> m;
    weights.resize(n);
    profits.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i] >> profits[i];
    }
    // dp[i][j] is maximum profit when you allow to take everything <= i
    // and have a knapsack capacity of j
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = m; j - weights[i] >= 0; --j)
        {
            dp[j] = max(profits[i] + dp[j - weights[i]], dp[j]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
