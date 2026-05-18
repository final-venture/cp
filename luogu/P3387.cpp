#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<int> a;
vector<vector<int>> adj;
vector<int> time_in;
vector<int> min_time;
vector<int> st;
vector<int> in_st;

vector<int> dp;
vector<int> node_to_scc_id;
vector<vector<int>> adj_scc;
vector<int> a_scc;

int timer;
int curr_scc_id;

void tarjan(int node) {
    time_in[node] = min_time[node] = ++timer;
    st.push_back(node);
    in_st[node] = 1;

    for (int nei : adj[node]) {
        if (!time_in[nei]) {
            tarjan(nei);
            min_time[node] = min(min_time[node], min_time[nei]);
        }
        else {
            if (in_st[nei]) {
                min_time[node] = min(min_time[node], time_in[nei]);
            }
        }
    }

    if (min_time[node] == time_in[node]) {
        int superval = 0;
        
        while (true) {
            int to_pop = st.back();
            superval += a[to_pop];
            node_to_scc_id[to_pop] = curr_scc_id;

            in_st[to_pop] = 0;
            st.pop_back();

            if (to_pop == node) {
                break;
            }
        }

        a_scc[curr_scc_id] = superval;
        ++curr_scc_id;
    }
}

int dfs(int node) {
    if (dp[node] != -1) {
        return dp[node];
    }
    
    int ret = a_scc[node];
    for (int nei : adj_scc[node]) {
        ret = max(ret, a_scc[node] + dfs(nei));
    }
    return dp[node] = ret;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    a.resize(n);
    adj.clear();
    adj.resize(n);
    time_in.assign(n, 0);
    min_time.assign(n, 0);
    st.clear();
    in_st.assign(n, 0);

    node_to_scc_id.resize(n);
    timer = 0;
    curr_scc_id = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
    }

    adj_scc.resize(n);
    a_scc.resize(n);
    dp.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!time_in[i]) {
            tarjan(i);
        }
    }

    for (int u = 0; u < n; ++u) {
        int u_scc_id = node_to_scc_id[u];
        for (auto v : adj[u]) {
            int v_scc_id = node_to_scc_id[v];
            if (u_scc_id != v_scc_id) {
                adj_scc[u_scc_id].push_back(v_scc_id);
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret = max(ret, dfs(i));
    }
    cout << ret << '\n';
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
