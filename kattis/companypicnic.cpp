#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXN = 1005;

unordered_map<string, int> s2i;
int timer;
vector<double> a;
vector<vector<int>> adj;
pair<int, double> dp[MAXN][2];

pair<int, double> dfs(int node, int par, int used) {
    if (dp[node][used].first != -1) {
        return dp[node][used];
    }

    pair<int, double> summ{0, 0};
    for (auto nei : adj[node]) {
        if (nei == par) {
            continue;
        }
        pair<int, double> notTake = dfs(nei, node, 0);
        pair<int, double> take = dfs(nei, node, 1);

        pair<int, double> toAdd = max(notTake, take);
        summ.first += toAdd.first;
        summ.second += toAdd.second;
    }

    if (used == 0) {
        return dp[node][used] = summ;
    }
    else {
        pair<int, double> ret{0, 0};
        for (auto nei : adj[node]) {
            if (nei == par) {
                continue;
            }
            pair<int, double> toSubtract = max(dp[nei][0], dp[nei][1]);
            ret = max(ret, {summ.first - toSubtract.first + dp[nei][0].first + 1,
                            summ.second - toSubtract.second + dp[nei][0].second + min(a[node], a[nei])});
        }
        return dp[node][used] = ret;
    }
}

int get_id(const string& s) {
    if (s2i.find(s) == s2i.end()) {
        s2i[s] = timer++;
    }
    return s2i[s];
}

void solve() {
    int n;
    cin >> n;
    s2i.clear();
    adj.clear();
    timer = 0;
    a.resize(n);
    adj.resize(n);

    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j <= 1; ++j) {
            dp[i][j] = {-1, 0};
        }
    }

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cin >> a[get_id(s)];
        string pred;
        cin >> pred;
        if (pred != "CEO") {
            adj[get_id(s)].push_back(get_id(pred));
            adj[get_id(pred)].push_back(get_id(s));
        }
    }

    pair<int, double> p1 = dfs(0, -1, 0);
    pair<int, double> p2 = dfs(0, -1, 1);
    pair<int, double> ret = max(p1, p2);

    cout << ret.first << ' ' << ret.second / ret.first << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(8);
    solve();
    return 0;
}
