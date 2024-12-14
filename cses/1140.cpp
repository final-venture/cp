#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()

void init() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> a(n);
    for (int i = 0; i < n; ++i) {
        ll s, e, p;
        cin >> s >> e >> p;
        a[i] = {{s, e}, p};
    }

    sort(all(a)); // Sort projects by start time, then end time
    // for (auto [x, y] : a)
    // {
    //     cout << x.first << ' ' << x.second << ' ' << y << '\n';
    // }

    vector<ll> dp(n + 1, 0);
    set<pair<ll, ll>> starts; // {start time, index}
    starts.insert({1e14, n}); // Boundary condition

    for (int i = n - 1; i >= 0; --i) {
        ll s = a[i].first.first, e = a[i].first.second;
        ll p = a[i].second;

        // Find the next project that starts after the current one ends
        auto it = starts.lower_bound({e + 1, -1ll});
        ll idx = it->second;

        dp[i] = max(dp[i + 1], p + dp[idx]);
        starts.insert({s, i}); // Insert current project in the set
    }

    cout << dp[0] << '\n'; // Maximum profit
}

int main() {
    init();
    solve();
    return 0;
}
