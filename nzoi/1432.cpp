#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

int n, m;
vector<int> par;
vector<vector<int>> adj;
vector<int> n2o;

struct Data
{
    int minn = INT_MAX, maxx = INT_MIN, summ = 0;
};

vector<Data> node_info;

Data merge(Data d1, Data d2)
{
    return {min(d1.minn, d2.minn), max(d1.maxx, d2.maxx), d1.summ + d2.summ};
}

Data dfs(int node)
{
    if (adj[node].empty())
        return node_info[node] = {n2o[node], n2o[node], 1};
    Data ret;
    for (int nei : adj[node])
    {
        ret = merge(ret, dfs(nei));
    }
    return node_info[node] = ret;
}

void solve()
{
    cin >> n >> m;
    par.resize(n - 1);
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> par[i];
        adj[par[i]].push_back(i + 1);
    }
    n2o.resize(n);
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        n2o[x] = i;
    }
    node_info.resize(n);
    dfs(0);

    // for (int i = 0; i < n; ++i)
    // {
    //     cout << node_info[i].maxx << ' ' << node_info[i].minn << ' ' << node_info[i].summ;
    //     cout << '\n';
    // }

    for (int i = 0; i < n; ++i)
    {
        if (node_info[i].maxx - node_info[i].minn + 1 != node_info[i].summ)
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
