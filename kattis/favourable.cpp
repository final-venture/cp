#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int S;
vector<int> dp;
vector<vector<int>> a;
const int MAXPG = 405;

int dfs(int idx) {
    if (a[idx][0] == -1) {
        return 1;
    }
    else if (a[idx][0] == 0) {
        return 0;
    }

    if (dp[idx] != -1) {
        return dp[idx];
    }

    int ret = 0;
    for (int nei : a[idx]) {
        ret += dfs(nei);
    }
    return dp[idx] = ret;
}

void solve() {
    cin >> S;
    dp.assign(MAXPG + 1, -1);
    a.assign(MAXPG + 1, {});

    for (int i = 0; i < S; ++i) {
        int pg;
        cin >> pg;
        cin >> ws;

        if (cin.peek() == 'f') {
            string garb;
            cin >> garb;
            a[pg].push_back(-1);
        }
        else if (cin.peek() == 'c') {
            string garb;
            cin >> garb;
            a[pg].push_back(0);
        }
        else {
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                a[pg].push_back(x);
            }
        }
    }

    // for (int i = 0; i < S; ++i) {
    //     int sz = a[i].size();
    //     for (int j = 0; j < sz; ++j) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dfs(1) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
