#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

void solve()
{
    int n, h;
    cin >> n >> h;
    vector<pair<int, int>> arr(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    vector<int> dp(h + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        auto &[w1, w2] = arr[i];
        for (int j = h; j >= 1; --j)
        {
            if (j - w1 >= 0)
                dp[j] |= dp[j - w1];
            if (j - w2 >= 0)
                dp[j] |= dp[j - w2];
        }
    }

    // for (auto x : dp)
    //     cout << x << ' ';
    // cout << '\n';

    for (int i = h; i >= 0; --i)
    {
        if (dp[i])
        {
            cout << i;
            return;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
