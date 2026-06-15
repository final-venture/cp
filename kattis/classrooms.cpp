#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> interval(n);
    for (int i = 0; i < n; ++i) {
        cin >> interval[i].first >> interval[i].second;
    }
    sort(interval.begin(), interval.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    });

    // for (auto [st, ed] : interval) {
    //     cerr << st << ' ' << ed << '\n';
    // }
        
    multiset<int> lst;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        auto [st, ed] = interval[i];
        auto it = lst.lower_bound(st);
        if (it != lst.begin()) {
            --it;
            lst.erase(it);
            lst.insert(ed);
            ++ret;
        }
        else if (lst.size() < k) {
            lst.insert(ed);
            ++ret;
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
