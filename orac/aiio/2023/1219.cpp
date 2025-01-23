#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    vector<pair<int, int>> intervals(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());
    int j = 0;
    vector<int> minStart(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        while (intervals[j].first <= i && intervals[j].second < i)
        {
            ++j;
        }
        if (intervals[j].first <= i)
        {
            minStart[i] = intervals[j].first;
        }
        else
        {
            minStart[i] = i;
        }
    }
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = max(dp[i - 1], dp[minStart[i] - 1] + arr[i]);
    }
    cout << dp[n];
}

signed main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
