#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const vector<pair<int, int>> dirs {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int n, m;
inline bool valid(int r, int c) {
    return (r >= 0 && r < n + 2 && c >= 0 && c < m + 2);
}

void solve()
{
    cin >> n >> m;
    vector<vector<char>> a(n + 2, vector<char>(m + 2, '.'));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> vals(n + 2, vector<int>(m + 2, -1));

    queue<pair<int, int>> q;
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            if (a[i][j] == '.') {
                q.push({i, j});
                vals[i][j] = 0;
            }
        }
    }

    int maxx = 0;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        maxx = max(maxx, vals[r][c]);
        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (!valid(nr, nc)) {
                continue;
            }
            if (vals[nr][nc] != -1) {
                continue;
            }
            if (a[nr][nc] == 'T') {
                q.push({nr, nc});
                vals[nr][nc] = 1 + vals[r][c];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (maxx <= 9) {
                if (vals[i][j] == 0) {
                    cout << "..";
                }
                else if (vals[i][j] <= 9) {
                    cout << '.' << vals[i][j];
                }
            }
            else {
                if (vals[i][j] == 0) {
                    cout << "...";
                }
                else if (vals[i][j] <= 9) {
                    cout << ".." << vals[i][j];
                }
                else {
                    cout << '.' << vals[i][j];
                }
            }
        }
        cout << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
