#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(a);
    vector<int> seen(n + 1, 0);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == b)
        {
            cout << 1;
            return;
        }
        if (seen[node])
            continue;
        seen[node] = 1;
        for (int nei : adj[node])
        {
            q.push(nei);
        }
    }
    cout << 0;
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
