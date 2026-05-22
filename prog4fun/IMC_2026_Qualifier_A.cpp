#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n, m, q;
vector<pair<int, pair<int, int>>> edges;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> up;
vector<vector<int>> miniMax;
vector<int> depth;
int LOG;

struct UF {
    vector<int> par;
    vector<int> sz;

    UF(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(int x1, int x2) {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2) {
            return;
        }
        if (sz[p1] < sz[p2]) {
            // move tree with parent p1 to tree with parent p2.
            par[p1] = par[p2];
            sz[p2] += sz[p1];
        }
        else {
            par[p2] = par[p1];
            sz[p1] += sz[p2];
        }
    }
};

void kruskal(UF& uf) {
    sort(edges.begin(), edges.end());
    for (auto& [w, p] : edges) {
        auto [u, v] = p;
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
    }
}

void dfs(int node, int par, int parWt) {
    depth[node] = 1 + depth[par];
    up[node][0] = par;
    miniMax[node][0] = parWt;

    for (int j = 1; j < LOG; ++j) {
        up[node][j] = up[up[node][j - 1]][j - 1];
        miniMax[node][j] = max(miniMax[node][j - 1], miniMax[up[node][j - 1]][j - 1]);
    }

    for (auto [neiWt, neiNode] : adj[node]) {
        if (neiNode == par) {
            continue;
        }
        dfs(neiNode, node, neiWt);
    }
}

int get_bottleneck(int u, int v) {
    // make sure v is deeper or same
    if (depth[v] < depth[u]) {
        swap(u, v);
    }
    assert(depth[u] <= depth[v]);
    int depth_diff = depth[v] - depth[u];
    int ret = 0;

    for (int j = LOG - 1; j >= 0; --j) {
        if ((depth_diff >> j) & 1) {
            ret = max(ret, miniMax[v][j]);
            v = up[v][j];
        }
    }

    if (u == v) {
        return ret;
    }

    for (int j = LOG - 1; j >= 0; --j) {
        if (up[v][j] != up[u][j]) {
            ret = max({ret, miniMax[u][j], miniMax[v][j]});
            v = up[v][j];
            u = up[u][j];
        }
    }

    ret = max({ret, miniMax[u][0], miniMax[v][0]});
    return ret;
}

void solve()
{
    cin >> n >> m >> q;
    LOG = 68 - __builtin_clzll(n);
    adj.clear();
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    UF uf(n + 1);
    kruskal(uf);

    up.resize(n + 1, vector<int>(LOG));
    miniMax.resize(n + 1, vector<int>(LOG));
    depth.resize(n + 1);
    depth[1] = 0;

    dfs(1, 1, 0);

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 0; j < LOG; ++j) {
    //         cout << up[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 0; j < LOG; ++j) {
    //         cout << miniMax[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; ++i) {
    //     cout << depth[i] << ' ';
    // }

    int maxBottleneck = 0;
    int ref = -1;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            maxBottleneck = 0;
            ref = -1;
        }
        else if (type == 2) {
            int x;
            cin >> x;
            if (ref != -1) {
                maxBottleneck = max(maxBottleneck, get_bottleneck(ref, x));
            }
            else {
                ref = x;
            }
        }
        else if (type == 3) {
            cout << maxBottleneck << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
