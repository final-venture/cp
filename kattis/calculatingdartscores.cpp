#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void print(pair<int, int>& score) {
    if (score.first == 0) {
        return;
    }
    string s;
    if (score.second == 1) {
        s = "single";
    }
    else if (score.second == 2) {
        s = "double";
    }
    else {
        s = "triple";
    }
    cout << s << ' ' << score.first / score.second << '\n';
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> valid {{0, 0}};
    for (int i = 1; i <= 20; ++i) {
        valid.push_back({i, 1});
        valid.push_back({2 * i, 2});
        valid.push_back({3 * i, 3});
    }
    // for (auto [x, y] : valid) {
    //     cerr << x << ' ';
    // }
    int sz = valid.size();
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            for (int k = 0; k < sz; ++k) {
                if (valid[i].first + valid[j].first + valid[k].first == n) {
                    print(valid[i]);
                    print(valid[j]);
                    print(valid[k]);
                    return;
                }
            }
        }
    }
    cout << "impossible" << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
