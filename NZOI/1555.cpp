#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

int n;
vector<pair<int, int>> dirs{{2, 1}, {-2, 1}, {1, 2}, {-1, 2}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

bool valid(int r, int c) {
    if (r < 0 || c < 0) {
        return false;
    }
    if (r >= n || c >= n) {
        return false;
    }
    return true;
}

int bfs(int ri, int ci, int rv, int cv) {
    vector<vector<int>> seen(n, vector<int>(n, 0));
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {ri, ci}});
    while (!q.empty()) {
        auto [dist, p] = q.front();
        auto [cr, cc] = p;
        q.pop();
        if (seen[cr][cc]) {
            continue;
        }
        seen[cr][cc] = 1;
        if (cr == rv && cc == cv) {
            // cout << dist << endl;
            return dist;
        }
        for (auto& [dr, dc] : dirs) {
            int nr = cr + dr, nc = cc + dc;
            if (valid(nr, nc) && !seen[nr][nc]) {
                q.push({dist + 1, {nr, nc}});
            }
        }
    }
    return -1;
}

void solve()
{
    int ri, ci, rv, cv;
    cin >> n;
    while (true) {
        cin >> ri >> ci >> rv >> cv;
        if (ri == 0 && ci == 0 && rv == 0 && cv == 0) {
            break;
        }
        --ri; --ci; --rv; --cv;
        cout << bfs(ri, ci, rv, cv) << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
