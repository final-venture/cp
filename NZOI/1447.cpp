#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007

using namespace std;

int n, m;
vector<int> n2l;
vector<vector<int>> adj;
vector<int> ret;

map<int, int> dfs(int node, int par, int depth)
{
    map<int, int> curr_map;
    for (int nei : adj[node])
    {
        if (nei == par) continue;
        map<int, int> lower_map = dfs(nei, node, depth + 1);
        if (lower_map.size() > curr_map.size())
        {
            lower_map.swap(curr_map); // lower_map will always be smaller, so we merge lower_map elements into curr_map
        }

        for (auto [lang, dep] : lower_map)
        {
            if (curr_map.count(lang))
            {
                ret[lang] = min(ret[lang], curr_map[lang] + dep - depth * 2);
                curr_map[lang] = min(curr_map[lang], dep);
            }
            else
            {
                curr_map[lang] = dep;
            }
        }
    }
    if (curr_map.find(n2l[node]) != curr_map.end())
    {
        ret[n2l[node]] = min(ret[n2l[node]], curr_map[n2l[node]] - depth);
    }
    curr_map[n2l[node]] = depth;
    return curr_map;
}

void solve()
{
    cin >> n >> m;
    n2l.resize(n);
    adj.resize(n);
    ret.resize(m, INT_MAX);
    for (int i = 0; i < n; ++i)
    {
        cin >> n2l[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, 0);
    for (int i = 0; i < m; ++i)
    {
        if (ret[i] == INT_MAX)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << ret[i] << '\n';
        }
    }
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
