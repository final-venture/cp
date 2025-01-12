
// 19:35
#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007

using namespace std;

int n, s, e;
vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, pair<int, int>>>> adj2;
// dp_in[node] stores the maximum amount that c is lower than d for subtree of node
// dp_out[node] stores `` for all paths that require outward edge traversal
vector<int> dp_in;
vector<int> dp_out;

int dfsIn(int node, int par)
{
    // if (adj[node].size() == 1 && par != -1)
    // {
    //     return dp_in[node] = 0;
    // }
    int minn = 0;
    for (auto [neiDiff, neiNode] : adj[node])
    {
        if (neiNode == par)
            continue;
        minn = min(minn, dfsIn(neiNode, node) + neiDiff);
    }
    return dp_in[node] = minn;
}

void dfsOut(int node, int par)
{
    int min1 = 1e9, min2 = 1e9;
    for (auto [neiDiff, neiNode] : adj[node])
    {
        if (neiNode == par)
            continue;
        if (dp_in[neiNode] + neiDiff <= min1)
        {
            min2 = min1;
            min1 = dp_in[neiNode] + neiDiff;
        }
        else if (dp_in[neiNode] + neiDiff < min2)
        {
            min2 = dp_in[neiNode] + neiDiff;
        }
    }
    for (auto [neiDiff, neiNode] : adj[node])
    {
        if (neiNode == par)
            continue;
        int minn = (dp_in[neiNode] + neiDiff == min1) ? min2 : min1;
        dp_out[neiNode] = min(minn + neiDiff, dp_out[node] + neiDiff);
        dfsOut(neiNode, node);
    }
}

int dijk(bool c)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dists(n, 1e9);
    pq.push({0, s});
    dists[s] = 0;
    while (!pq.empty())
    {
        auto [dist, node] = pq.top();
        pq.pop();
        if (node == e)
            return dist;
        if (dist > dists[node])
            continue;
        for (auto &[neiNode, p] : adj2[node])
        {
            auto [dc, dd] = p;
            if (c)
            {
                if (dc + dist < dists[neiNode])
                {
                    dists[neiNode] = dc + dist;
                    pq.push({dc + dist, neiNode});
                }
            }
            else
            {
                if (dd + dist < dists[neiNode])
                {
                    dists[neiNode] = dd + dist;
                    pq.push({dd + dist, neiNode});
                }
            }
        }
    }
    return 0 / 0;
}

void solve()
{
    cin >> n >> s >> e;
    adj.resize(n);
    adj2.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int diff = c - d;
        adj[a].push_back({diff, b});
        adj[b].push_back({diff, a});
        adj2[a].push_back({b, {c, d}});
        adj2[b].push_back({a, {c, d}});
    }
    dp_in.resize(n);
    dp_out.resize(n);
    dfsIn(0, -1);
    dp_out[0] = 0;
    dfsOut(0, -1);

    // for (int x : dp_in) cout << x << ' ';
    // cout << '\n';
    // for (int x : dp_out) cout << x << ' ';
    // cout << '\n';

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dp_out[i] < 0 || dp_in[i] < 0)
            ++cnt;
    }
    if (cnt > (n - 1) / 2)
    {
        // cout << 'x';
        cout << dijk(true);
    }
    else
    {
        // cout << 'h';
        cout << dijk(false);
    }
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
