#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, d;
    cin >> n >> d;

    // 1 is the weight, 2.1 is the leap capacity, 2.2 is the height.
    vector<pair<int, pair<int, int>>> frogs(n);
    for (int i = 0; i < n; ++i) {
        cin >> frogs[i].second.first >> frogs[i].first >> frogs[i].second.second;
    }

    sort(frogs.begin(), frogs.end(), greater<>());
    int maxWt = 0;
    for (int i = 0; i < n; ++i) {
        maxWt = max(maxWt, frogs[i].first);
    }
    vector<int> dp(maxWt + 1, 0);
    int ret = 0;

    int currFinalised = maxWt - 1;
    for (int i = 0; i < n; ++i) {
        int currWt = frogs[i].first;
        int currHt = frogs[i].second.second;
        int currLp = frogs[i].second.first;

        while (currFinalised > currWt - 1) {
            dp[currFinalised] = max(dp[currFinalised], dp[currFinalised + 1]);
            --currFinalised;
        }

        if (dp[currWt] + currLp > d) {
            ++ret;
        }

        for (int j = 0; j <= currWt - 1; ++j) {
            if (j + currWt <= maxWt) {
                dp[j] = max(dp[j], dp[min(maxWt, j + currWt)] + currHt);
            }
            if (j == currWt - 1) {
                dp[j] = max(dp[j], dp[min(maxWt, 2 * currWt - 1)] + currHt);
            }
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



// Always best to get frogs out from lightest to heaviest.
// Sort the frogs by weight descending
// dp without an index parameter, track max height reached with each remaining capacity of a pile