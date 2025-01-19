#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());
    set<int> ends;
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        auto &[st, ed] = intervals[i];
        if (!ends.empty() && st > *ends.begin())
        {
            ++ret;
            ends.clear();
        }
        ends.insert(ed);
    }
    if (!ends.empty())
    {
        ++ret;
    }
    cout << ret;
}

signed main()
{
#ifndef LOCAL
    freopen("shotin.txt", "r", stdin);
    freopen("shotout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
