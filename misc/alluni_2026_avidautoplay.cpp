#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

struct UF {
    vector<int> par;
    vector<int> size;

    UF(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0LL);
        size.assign(n, 1);
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
        if (size[p1] > size[p2]) {
            par[p2] = par[p1];
            size[p1] += size[p2];
        }
        else {
            par[p1] = par[p2];
            size[p2] += size[p1];
        }
    }
};

vector<vector<pair<int, int>>> adj;
int n;

// returns the min on the path so far
int dfs(int node, int par) {
    if (node == n) {
        return 0;
    }
    int ret = 3e14;
    for (auto [neiW, neiN] : adj[node]) {
        if (neiN == par) {
            continue;
        }
        ret = min(ret, max(neiW, dfs(neiN, node)));
    }
    return ret;
}

void solve()
{
    cin >> n;
    unordered_map<string, vector<pair<int, int>>> cc_a;
    unordered_map<string, vector<pair<int, int>>> cc_g;
    unordered_map<int, vector<pair<int, int>>> cc_y;
    for (int i = 1; i <= n; ++i) {
        int score, year;
        string artist, genre;
        cin >> score >> artist >> genre >> year;
        cc_a[artist].push_back({score, i});
        cc_g[genre].push_back({score, i});
        cc_y[year].push_back({score, i});
    }

    vector<tuple<int, int, int>> edges;
    for (auto& [artist, cc] : cc_a) {
        sort(cc.begin(), cc.end());
        int sz = cc.size();
        for (int i = 1; i < sz; ++i) {
            auto& [score1, u] = cc[i - 1];
            auto& [score2, v] = cc[i];
            int w = abs(score1 - score2);
            edges.push_back({w, u, v});
            // edges.push_back({w, v, u});
        }
    }
    for (auto& [genre, cc] : cc_g) {
        sort(cc.begin(), cc.end());
        int sz = cc.size();
        for (int i = 1; i < sz; ++i) {
            auto& [score1, u] = cc[i - 1];
            auto& [score2, v] = cc[i];
            int w = abs(score1 - score2);
            edges.push_back({w, u, v});
            // edges.push_back({w, v, u});
        }
    }
    for (auto& [year, cc] : cc_y) {
        sort(cc.begin(), cc.end());
        int sz = cc.size();
        for (int i = 1; i < sz; ++i) {
            auto& [score1, u] = cc[i - 1];
            auto& [score2, v] = cc[i];
            int w = abs(score1 - score2);
            edges.push_back({w, u, v});
            // edges.push_back({w, v, u});
        }
    }

    adj.clear();
    adj.resize(n + 1);
    UF uf(n + 1);
    sort(edges.begin(), edges.end());
    // for (auto [w, u, v] : edges) {
    //     cout << w << ' ' << u << ' ' << v << '\n';
    // }
    for (auto& [w, u, v] : edges) {
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
    }

    int ret = dfs(1, -1);
    cout << ((ret >= 3e14) ? -1 : ret) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
