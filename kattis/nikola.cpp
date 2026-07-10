#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int N;
vector<int> a;
const int MAXN = 1005;
const int INF = 1e12;
int dp[MAXN][MAXN];

int dfs(int idx, int step) {
    if (idx == N - 1) {
        return 0;
    }
    if (step >= N - 1) {
        return INF;
    }
    if (dp[idx][step] != -1) {
        return dp[idx][step];
    }

    int forward = INF;
    if (idx + step < N) {
        forward = dfs(idx + step, step + 1) + a[idx + step];
    }
    int backward = INF;
    if (idx != 0 && idx - step + 1 >= 0) {
        backward = dfs(idx - step + 1, step) + a[idx - step + 1];
    }
    return dp[idx][step] = min(forward, backward);
}

void solve() {
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);

    cout << dfs(0, 1) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
