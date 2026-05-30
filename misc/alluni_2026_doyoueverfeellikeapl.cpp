#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

unordered_map<char, pair<int, int>> dirs {{'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}, {'X', {0, 0}}};

void solve()
{
    int m, n;
    cin >> m >> n;
    int targX, targY;
    cin >> targX >> targY;
    string s; 
    cin >> s;

    vector<pair<int, int>> pfx(m + 1);
    pfx[0] = {0, 0};
    for (int i = 1; i <= m; ++i) {
        int c = s[i - 1];
        auto [dx, dy] = dirs[c];
        pfx[i].first = pfx[i - 1].first + dx;
        pfx[i].second = pfx[i - 1].second + dy;
    }

    vector<pair<int, int>> good(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        good[i] = {x, y};
    }

    // if we follow [st, i], we reach the tile: pfx[i] - pfx[st - 1] = {x, y}
    // so we can check the time that we reach some (x, y) by looking it up in a hashmap of pfx sum, since
    // pfx[i] = pfx[st - 1] + {x, y}.
    // enforce i >= st

    map<pair<int, int>, int> minTimeReached;

    int ret = 1e9;
    for (int st = m; st >= 0; --st) {
        minTimeReached[pfx[st]] = st;
        pair<int, int> subby = pfx[st];

        int tT = 1e9;
        pair<int, int> rhsT = {subby.first + targX, subby.second + targY};
        if (minTimeReached.find(rhsT) != minTimeReached.end()) {
            tT = minTimeReached[rhsT];
        }
        

        int tG = 1e9;
        for (auto [gx, gy] : good) {
            pair<int, int> rhsG = {subby.first + gx, subby.second + gy};
            if (minTimeReached.find(rhsG) != minTimeReached.end()) {
                tG = min(tG, minTimeReached[rhsG]);
            }
        }

        if (tT < tG) {
            ret = min(ret, st);
        }
    }

    if (ret >= 1e9) {
        cout << -1 << '\n';
    }
    else {
        cout << ret << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
