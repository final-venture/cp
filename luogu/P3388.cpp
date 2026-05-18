#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<vector<int>> adj;
vector<int> time_in, min_time;
int timer;
// might have to convert this into a set.
set<int> ret;

void tarjan(int node) {
    time_in[node] = min_time[node] = ++timer;

    int children = 0;

    for (int nei : adj[node]) {
        if (!time_in[nei]) {
            ++children;
            tarjan(nei);
            min_time[node] = min(min_time[node], min_time[nei]);

            if (min_time[nei] >= time_in[node] && min_time[node] != time_in[node]) {
                // criteria: min_time[nei] >= time_in[node] means node is an articulation point.
                // But we cannot count the root of the DFS.
                ret.insert(node);
            }
        }
        else {
            // if we check the criteria here, it will always be false
            // because time_in[nei] < time_in[node], therefore min_time[nei] < time_in[node]
            min_time[node] = min(min_time[node], time_in[nei]);
        }
    }

    if (min_time[node] == time_in[node] && children > 1) {
        ret.insert(node);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    time_in.assign(n, 0);
    min_time.resize(n);
    timer = 0;
    ret.clear();

    for (int i = 0; i < n; ++i) {
        if (!time_in[i]) {
            tarjan(i);
        }
    }

    int ret_sz = ret.size();
    cout << ret_sz << " \n";
    for (auto x : ret) {
        cout << x + 1 << ' ';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}