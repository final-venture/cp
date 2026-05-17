#include <bits/stdc++.h>

#define ll long long
#define MOD 5000000
#define int ll

using namespace std;

int n, k;
vector<int> seg;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.first == p2.first)
    {
        return (p1.second < p2.second);
    }
    return (p1.first > p2.first);
}

void update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        seg[idx] = v;
        return;
    }
    if (l > t || r < t)
    {
        return;
    }
    int m = l + (r - l) / 2;
    update(idx * 2 + 1, l, m, t, v);
    update(idx * 2 + 2, m + 1, r, t, v);
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
}

int query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (r < ql || l > qr)
    {
        return 0;
    }
    int m = l + (r - l) / 2;
    int left = query(idx * 2 + 1, l, m, ql, qr);
    int right = query(idx * 2 + 2, m + 1, r, ql, qr);
    return left + right;
}

void do_update(int t, int v)
{
    update(0, 0, n - 1, t, v);
}

int do_query(int ql, int qr)
{
    return query(0, 0, n - 1, ql, qr);
}

void solve()
{
    cin >> n >> k;
    vector<int> arr(n);
    seg.resize(4 * n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    vector<pair<int, int>> sorted(n);
    for (int i = 0; i < n; ++i)
    {
        sorted[i] = {arr[i], i};
    }
    sort(sorted.begin(), sorted.end(), cmp);
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    for (int j = 0; j < n; ++j)
    {
        dp[0][j] = 1;
    }
    unordered_map<int, int> cnt;
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            auto [num, idx] = sorted[j];
            do_update(idx, dp[i - 1][idx]);
            int ahead = do_query(idx + 1, n - 1);
            // cout << ahead << '\n';
            dp[i][idx] = ahead;
            dp[i][idx] %= MOD;
            // ++cnt[num];
        }
        // cnt.clear();
        seg.assign(4 * n, 0);
    }
    // for (int i = 0; i < k + 1; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ret = 0;
    for (int j = 0; j < n; ++j)
    {
        ret += dp[k - 1][j];
        ret %= MOD;
    }
    cout << ret;
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
