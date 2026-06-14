#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// deliver by distance, with largest dist from post office going first.
// number of trips required to finish each house i is ceil(t[i] / K), remaining amount is ceil(t[i] / K) * K - t[i].
//  this amount should be propagated to the next houses UNLESS switching signs (can be multiple).

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> loc(N);
    for (int i = 0; i < N; ++i) {
        cin >> loc[i].first >> loc[i].second;
    }
    sort(loc.begin(), loc.end());

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        if (loc[i].second == 0 || loc[i].first > 0) {
            continue;
        }
        auto [x, t] = loc[i];
        int trips = (t + K - 1) / K;
        int quota = trips * K;
        ret += trips * abs(x) * 2;
        int idx = i;
        while (idx < N && quota > 0 && loc[idx].first < 0) {
            int toSub = min(quota, loc[idx].second);
            quota -= toSub;
            loc[idx].second -= toSub;
            ++idx;
        }
    }

    for (int i = N - 1; i >= 0; --i) {
        if (loc[i].second == 0 || loc[i].first < 0) {
            continue;
        }
        auto [x, t] = loc[i];
        int trips = (t + K - 1) / K;
        int quota = trips * K;
        ret += trips * abs(x) * 2;
        int idx = i;
        while (idx >= 0 && quota > 0 && loc[idx].first > 0) {
            int toSub = min(quota, loc[idx].second);
            quota -= toSub;
            loc[idx].second -= toSub;
            --idx;
        }
    }

    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
