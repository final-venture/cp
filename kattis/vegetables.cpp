#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    double T;
    cin >> T;
    int N;
    cin >> N;

    double minn = 1e9;
    vector<double> w(N);
    for (int i = 0; i < N; ++i) {
        cin >> w[i];
        minn = min(minn, w[i]);
    }

    priority_queue<pair<double, int>> pq;
    for (int i = 0; i < N; ++i) {
        pq.push({w[i], 0});
    }

    int ret = 0;
    while (!pq.empty()) {
        if ((1.0 * minn / pq.top().first) > T) {
            break;
        }

        auto [wt, cuts] = pq.top();
        pq.pop();
        pq.push({wt * (cuts + 1) / (cuts + 2), cuts + 1});
        minn = min(minn, wt * (cuts + 1) / (cuts + 2));
        ++ret;
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
