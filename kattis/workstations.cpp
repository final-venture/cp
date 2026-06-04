#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// 1, 5
// 6, 3
// 14, 6


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> as(n);
    for (int i = 0; i < n; ++i) {
        cin >> as[i].first >> as[i].second;
    }
    sort(as.begin(), as.end());
    priority_queue<int, vector<int>, greater<>> avail;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        // a is the time of arrival, s is how long they stay.
        auto [a, s] = as[i];
        while (!avail.empty() && avail.top() + m < a) {
            avail.pop();
        }
        if (!avail.empty() && avail.top() <= a) {
            avail.pop();
            avail.push(a + s);
        }
        else {
            ++ret;
            avail.push(a + s);
        }
    }

    cout << n - ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
