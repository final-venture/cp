#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int N;
vector<pair<int, int>> a;
const int MAXN = 42;
const int MAXX = 804;
const int MAXY = 804;
const int OFFSET = 402;
int dp[MAXN][MAXX][MAXY];

int dfs(int idx, int x, int y) {
    if (idx >= N) {
        if (x == 0 && y == 0) {
            return 1;
        }
        return 0;
    }
    if (dp[idx][x + OFFSET][y + OFFSET] != -1) {
        return dp[idx][x + OFFSET][y + OFFSET];
    }

    int take = dfs(idx + 1, x + a[idx].first, y + a[idx].second);
    int notTake = dfs(idx + 1, x, y);

    return dp[idx][x + OFFSET][y + OFFSET] = take + notTake;
}

void solve() {
    cin >> N;
    a.resize(N);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    cout << dfs(0, 0, 0) - 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
