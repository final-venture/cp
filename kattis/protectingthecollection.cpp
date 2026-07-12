#include <bits/stdc++.h>

using namespace std;

// #define int long long
#define EPS 1e-9

const int MAXN = 2003;

// ACW
const vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dp[MAXN][MAXN][4][2];
vector<vector<char>> grid;
int n, COL, ROW;

inline bool check(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n) {
        return false;
    }
    return true;
}

// 0 -> 3
// 1 -> 2
// 2 -> 1
// 3 -> 0
inline int slashTurn(int dir) { return (3 - dir); }

// 0 -> 1
// 1 -> 0
// 2 -> 3
// 3 -> 2
inline int backSlashTurn(int dir) { return (3 - dir + 2) % 4; }

int dfs(int r, int c, int dir, int placed) {
    if (!check(r, c)) {
        if (r == ROW - 1 && c == n && dir == 1) {
            return true;
        }
        return false;
    }

    if (dp[r][c][dir][placed] != -1) {
        return dp[r][c][dir][placed];
    }

    int ret = false;
    int newDir;
    if (grid[r][c] == '\\') {
        newDir = backSlashTurn(dir);
    }
    else if (grid[r][c] == '/') {
        newDir = slashTurn(dir);
    }
    else if (grid[r][c] == '.') {
        newDir = dir;
    }

    auto [dr, dc] = dirs[newDir];
    ret |= dfs(r + dr, c + dc, newDir, placed);

    // can we override mirrors? assume not
    if (!placed && grid[r][c] == '.') {
        int cand1 = slashTurn(dir);
        int cand2 = backSlashTurn(dir);
        auto [dr1, dc1] = dirs[cand1];
        auto [dr2, dc2] = dirs[cand2];
        ret |= dfs(r + dr1, c + dc1, cand1, 1);
        ret |= dfs(r + dr2, c + dc2, cand2, 1);
    }
    return dp[r][c][dir][placed] = ret;
}

void solve() {
    cin >> n >> COL >> ROW;
    grid.resize(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    int ret = dfs(0, COL - 1, 0, 0);
    cout << (ret ? "YES" : "NO") << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
