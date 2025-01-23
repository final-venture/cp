#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

int n, k;
vector<int> discs;
vector<vector<int>> p;
int dp[305][305][305];

int dfs(int layer, int idx, int disc)
{
    if (layer == n)
    {
        return 0;
    }
    if (dp[layer][idx][disc] != -1)
    {
        return dp[layer][idx][disc];
    }
    int ret = -1e18;
    for (int i = idx; i < idx + 2; ++i)
    {
        ret = max(ret, dfs(layer + 1, i, disc) + p[layer][idx]);
        if (disc < k)
            ret = max(ret, dfs(layer + 1, i, disc + 1) + discs[disc]);
    }
    return dp[layer][idx][disc] = ret;
}

void solve()
{
    cin >> n >> k;
    discs.resize(k);
    p.resize(n);
    for (int i = 0; i < k; ++i)
    {
        cin >> discs[i];
    }
    sort(discs.begin(), discs.end(), greater<>());

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            int x;
            cin >> x;
            p[i].push_back(x);
        }
    }

    memset(dp, -1, sizeof dp);
    cout << dfs(0, 0, 0);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
