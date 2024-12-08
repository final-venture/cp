#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define int ll

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int n, q;
vector<int> a;
vector<int> tour_in;
vector<int> tour_out;
vector<vector<int>> adj;
int cnt = 1;
vector<int> seg;
vector<int> arr;

void dfs(int node, int par)
{
    tour_in[node] = cnt;
    arr[tour_in[node]] = a[node];
    ++cnt;
    for (int nei : adj[node])
    {
        if (nei == par) continue;
        dfs(nei, node);
    }
    tour_out[node] = cnt;
}

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = arr[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2, l, m);
    build(idx * 2 + 1, m + 1, r);
    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

int query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (qr < l || r < ql)
    {
        return 0;
    }
    int m = l + (r - l) / 2;
    int left = query(idx * 2, l, m, ql, qr);
    int right = query(idx * 2 + 1, m + 1, r, ql, qr);
    return left + right;
}

int update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        a[l] = v;
        seg[idx] = v;
        return seg[idx];
    }
    if (l > t || r < t)
    {
        return seg[idx];
    }
    int m = l + (r - l) / 2;
    int left = update(idx * 2, l, m, t, v);
    int right = update(idx * 2 + 1, m + 1, r, t, v);
    return seg[idx] = left + right;
}

void solve()
{
    cin >> n >> q;
    a = vector<int>(n + 1); arr = vector<int>(n + 1);
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> a[i];
    }
    tour_in = vector<int>(n + 1); tour_out = vector<int>(n + 1);
    adj = vector<vector<int>>(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, -1);
    seg = vector<int>(4 * n + 10);
    build(1, 1, n);
    // for (int x : tour_in) cout << x << ' ';
    // cout << '\n';
    // for (int x : tour_out) cout << x << ' ';
    // cout << '\n';
    while (q--)
    {
        int cmd, node;
        cin >> cmd >> node;
        if (cmd == 1)
        {
            int v;
            cin >> v;
            int t = tour_in[node];
            // cout << "t is " << t << '\n';
            update(1, 1, n, t, v);
        }
        else
        {
            int ql = tour_in[node]; int qr = tour_out[node] - 1;
            cout << query(1, 1, n, ql, qr) << '\n';
        }
    }
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
