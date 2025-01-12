#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;

void solve()
{
    cin >> n >> m;
    vector<vector<int>> adj(n + m + 1);
    vector<int> topo{1};
    vector<int> indeg(n + m + 1, 0);
    vector<double> water(n + m + 1, 0);
    water[1] = 1;
    for (int i = 1; i < n + 1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[i].push_back(v1);
        adj[i].push_back(v2);
        ++indeg[v1];
        ++indeg[v2];
    }
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int nei : adj[node])
        {
            --indeg[nei];
            if (!indeg[nei])
            {
                q.push(nei);
                topo.push_back(nei);
            }
        }
    }
    // for (int x : topo) cout << x << '\n';

    for (int u : topo)
    {
        for (int v : adj[u])
        {
            water[v] += water[u] / 2;
        }
    }
    for (int i = n + 1; i <= n + m; ++i)
    {
        cout << water[i] << '\n';
    }
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}