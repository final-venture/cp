#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int w, h;
    cin >> w >> h;
    int k;
    cin >> k;
    vector<pair<int, int>> intervals(k);
    for (int i = 0; i < k; ++i)
    {
        int p_i;
        cin >> p_i;
        pair<int, int> cand;
        cin >> cand.first >> cand.second;
        cand.second = cand.first;
        for (int j = 1; j < p_i; ++j)
        {
            int x, y;
            cin >> x >> y;
            cand.first = min(cand.first, x);
            cand.second = max(cand.second, x);
        }
        intervals[i] = cand;
    }
    sort(intervals.begin(), intervals.end());
    // for (auto &[st, ed] : intervals)
    // {
    //     cout << st << ' ' << ed << '\n';
    // }
    vector<pair<int, int>> merged;
    for (int i = 0; i < k; ++i)
    {
        if (merged.empty() || (merged.back().second < intervals[i].first))
        {
            merged.push_back(intervals[i]);
        }
        else
        {
            merged.back().second = max(merged.back().second, intervals[i].second);
        }
    }
    for (auto &[st, ed] : merged)
    {
        int not_ok = ed - st;
        w -= not_ok;
    }
    cout << w;
}

signed main()
{
#ifndef LOCAL
    freopen("spacein.txt", "r", stdin);
    freopen("spaceout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
