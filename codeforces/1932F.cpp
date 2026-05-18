#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// sort intervals by descending end time
// maintain an array maxEnd[i], denoting maximum end index of an interval that overlaps the point i
//  i.e. when we feed cats at i, where can we next feed them.
// maintain an array catCnt[i]: how many invervals overlap i
// use dp: dp[i] represents the maximum cats we can feed if we start feeding at i or later.
//  transition: dp[i] = max(dp[maxEnd[i]] + catCnt[i], dp[i + 1]).
//  base case: dp = {0}.

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> intervals(m);
    vector<pair<int, int>> events;

    for (int i = 0; i < m; ++i) {
        int st, ed;
        cin >> st >> ed;
        intervals[i] = {st, ed};

        events.push_back({st, 1});
        events.push_back({ed + 1, -1});
    }

    sort(intervals.begin(), intervals.end(), [] (pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    });

    // n + 3 is an impossible value, catCnt[n + 3] = 0;
    vector<int> maxEnd(n + 1, n + 3);
    int l = 1e9;
    for (int i = 0; i < m; ++i) {
        auto& [st, ed] = intervals[i];
        l = min(l, ed);
        for (int j = st; j <= l; ++j) {
            maxEnd[j] = ed;
        }
        l = min(l, st - 1);
        // if (i == 0) {
        //     for (auto x : maxEnd) {
        //         cout << x << ' ';
        //     }
        //     cout << "\n\n";
        // }
    }

    vector<int> catCnt(n + 5, 0);
    sort(events.begin(), events.end());
    int event_idx = 0;
    int curr_cat_cnt = 0;
    for (int curr_time = 1; curr_time <= n; ++curr_time) {
        while (event_idx < events.size() && events[event_idx].first <= curr_time) {
            int event_time = events[event_idx].first;
            int event_delta = events[event_idx].second;
            curr_cat_cnt += event_delta;
            ++event_idx;
        }
        catCnt[curr_time] = curr_cat_cnt;
    }

    // for (auto x : maxEnd) {
    //     cout << x << ' ';
    // }
    // cout << '\n';
    // for (auto x : catCnt) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    vector<int> dp(n + 5, 0);
    for (int i = n; i >= 1; --i) {
        dp[i] = max(dp[maxEnd[i] + 1] + catCnt[i], dp[i + 1]);
    }
    cout << dp[1] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
