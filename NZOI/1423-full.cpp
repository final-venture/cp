#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define int ll

// #define LOCAL

void init()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int n, m, k, u;
vector<vector<pair<int, int>>> adj;
vector<int> tour_in; vector<int> tour_out;
vector<int> seg;
vector<vector<pair<int, int>>> up;
int cnt = 0;

int query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (r < ql || l > qr)
    {
        return 0;
    }
    int mid = l + (r - l) / 2;
    int left = query(idx * 2 + 1, l, mid, ql, qr);
    int right = query(idx * 2 + 2, mid + 1, r, ql, qr);
    return left + right;
}

int update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        seg[idx] += v;
        return seg[idx];
    }
    if (r < t || l > t)
    {
        return seg[idx];
    }
    int mid = l + (r - l) / 2;
    int left = update(idx * 2 + 1, l, mid, t, v);
    int right = update(idx * 2 + 2, mid + 1, r, t, v);
    return seg[idx] = left + right;
}

void tour(int node)
{
    tour_in[node] = cnt;
    ++cnt;
    for (auto& [nei, neiDist] : adj[node])
    {
        up[nei][0] = {node, neiDist};
        tour(nei);
    }
    tour_out[node] = cnt;
}

void addTrout(int node, int s)
{
    update(0, 0, n - 1, tour_in[node], 1);
    // cout << tour_in[node] << '\n';
    for (int j = 16; j >= 0; --j)
    {
        auto& [upNode, upDist] = up[node][j];
        if (s >= upDist)
        {
            node = upNode;
            s -= upDist;
        }
    }
    // cout << n << '\n';
    if (node != 0)
    {
        // cout << tour_in[up[n][0].first] << '\n';
        update(0, 0, n - 1, tour_in[up[node][0].first], -1);
    }
}

void solve()
{
    cin >> n >> m >> k >> u;
    up = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(18, {0, 1e10}));
    adj.resize(n);
    tour_in.resize(n); tour_out.resize(n);
    seg.resize(4 * n, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d}); // dg - only need to consider one way
    }

    tour(0);

    for (int j = 1; j <= 16; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            auto& [n, d] = up[i][j - 1];
            up[i][j] = {up[n][j - 1].first, d + up[n][j - 1].second};
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int n, s; // n = starting node of trout, s = strength of trout
        cin >> n >> s;
        addTrout(n, s);
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     cout << tour_in[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << tour_out[i] << ' ';
    // }
    // cout << '\n';

    // for (int i = 0; i < 4 * n; ++i)
    // {
    //     cout << seg[i] << ' ';
    // }
    // cout << '\n';

    while (k--)
    {
        char cmd;
        cin >> cmd;
        if (cmd == 'Q')
        {
            int q;
            cin >> q;
            int ret = query(0, 0, n - 1, tour_in[q], tour_out[q] - 1);
            cout << ret << endl;
        }
        if (cmd == 'D')
        {
            int node, s;
            cin >> node >> s;
            addTrout(node, s);
        }
    }
}

signed main()
{
    init();
#ifdef LOCAL
    int t;
    cin >> t;
    while (t--)
#endif
        solve();
    return 0;
}
