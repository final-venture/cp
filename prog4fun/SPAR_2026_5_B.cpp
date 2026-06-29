#include <bits/stdc++.h>

// #define int long long
// #define double long double

using namespace std;

inline int dist2(int x1, int x2, int y1, int y2) { return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }

const int MAXV = 25 * 25 + 5;
const int MAXS = 9 * 25 * 25 + 5;

void solve() {
    int h, w, r, s;
    cin >> h >> w >> r >> s;
    s = min(MAXS, s);
    int r2 = r * r;
    int hasStarted = 0;
    int st = -1, ed = -1;
    vector<int> diff(MAXV);
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] != '.') { st = i * w + j; }
            if (!hasStarted && grid[i][j] != '.') {
                hasStarted = 1;
                ed = i * w + j;
            }
            if (grid[i][j] != '.') { diff[i * w + j] = grid[i][j] - '0'; }
        }
    }

    vector<vector<pair<double, int>>> adj(MAXV);
    for (int i1 = 0; i1 < h; ++i1) {
        for (int j1 = 0; j1 < w; ++j1) {
            int vertex1 = i1 * w + j1;
            if (grid[i1][j1] == '.') { continue; }
            for (int i2 = max(0, i1 - 4); i2 <= min(h - 1, i1 + 4); ++i2) {
                for (int j2 = max(0, j1 - 4); j2 <= min(w - 1, j1 + 4); ++j2) {
                    if (grid[i2][j2] == '.') { continue; }
                    int vertex2 = i2 * w + j2;
                    int distSquared = dist2(i1, i2, j1, j2);
                    if ((i1 == i2 && j1 == j2) || distSquared > r2) { continue; }
                    adj[vertex1].push_back({sqrt(distSquared), vertex2});
                }
            }
        }
    }

    vector<vector<double>> dists(MAXV, vector<double>(MAXS, 1e9));

    // dist[i][j] is the minimum dist to reach vertex i, using j energy.

    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
    pq.push({0, {diff[st], st}});
    dists[st][diff[st]] = 0;
    while (!pq.empty()) {
        auto& [distt, p] = pq.top();
        double dist = distt;
        auto [stam, node] = p;
        // cout << dist << '\n';
        pq.pop();
        if (stam > s) { continue; }
        if (node == ed) {
            cout << dist << '\n';
            return;
        }
        // cout << node << ' ' << stam << '\n';
        if (dists[node][stam] < dist) { continue; }

        for (auto& [neiDist, neiNode] : adj[node]) {
            if (dists[neiNode][stam + diff[neiNode]] <= dist + neiDist) { continue; }
            if (stam + diff[neiNode] > s) { continue; }
            dists[neiNode][stam + diff[neiNode]] = dist + neiDist;
            pq.push({dist + neiDist, {stam + diff[neiNode], neiNode}});
        }
    }

    cout << "impossible" << '\n';
}

signed main() {
    cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
