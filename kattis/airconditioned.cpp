#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N;
    cin >> N;
    vector<pair<int, int>> event(N);
    for (int i = 0; i < N; ++i) {
        cin >> event[i].first >> event[i].second;
    }
    sort(event.begin(), event.end());

    // [1, 4], [2, 3]
    // [1, 4], [5, 8]

    int ret = 0;
    int idx = 0;
    while (idx < N) {
        int currL = event[idx].first, currR = event[idx].second;
        ++idx;
        while (idx < N && event[idx].first <= currR) {
            currL = max(currL, event[idx].first);
            currR = min(currR, event[idx].second);
            ++idx;
        }
        // cerr << idx << ' ';
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
