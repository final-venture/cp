#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// 1. compress all sccs using tarjan's
// 2. find the outdegree of each scc
// 3. if there is more than one scc with outdegree == 0, then no cows can have high popularity
// 4. Otherwise, if there is exactly one scc with outdegree == 0, then the # of cows with
//      high popularity is the number of nodes in the scc.
// 5. No idea if you can have zero sccs with outdegree == 0, my intuition says this is not possible.
// Note: if graph is disconnected, instantly output 0.

// VARIABLES
vector<vector<int>> adj;
vector<int> time_in, min_time, st, in_st;
int timer;

int scc_timer;
vector<int> node_to_scc_id, scc_id_to_count;
vector<int> scc_id_to_outdegree;

void tarjan(int node) {
    time_in[node] = min_time[node] = ++timer;
    st.push_back(node); in_st[node] = 1;

    for (int nei : adj[node]) {
        if (!time_in[nei]) {
            tarjan(nei);
            min_time[node] = min(min_time[node], min_time[nei]);
        }
        else if (in_st[nei]) {
            min_time[node] = min(min_time[node], time_in[nei]);
        }
    }

    if (time_in[node] == min_time[node]) {
        // cout << "stack: " << '\n';
        // for (auto x : st) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        while (true) {
            int to_pop = st.back();
            node_to_scc_id[to_pop] = scc_timer;
            scc_id_to_count[scc_timer]++;

            st.pop_back();
            in_st[to_pop] = 0;

            if (to_pop == node) {
                break;
            }
        }

        ++scc_timer;
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
    }

    timer = 0;
    time_in.assign(n, 0); min_time.resize(n); st.clear(); in_st.assign(n, 0);

    scc_timer = 0;
    node_to_scc_id.resize(n); scc_id_to_count.assign(n, 0);

    for (int i = 0; i < n; ++i) {
        if (!time_in[i]) {
            tarjan(i);
        }
    }

    // for (auto x : node_to_scc_id) {
    //     cout << x << ' ';
    // }
    // cout << "\n\n";

    scc_id_to_outdegree.assign(n, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            if (node_to_scc_id[u] != node_to_scc_id[v]) {
                // cout << u << ' ' << v << '\n';
                scc_id_to_outdegree[node_to_scc_id[u]]++;
            }
        }
    }

    // for (int i = 0; i < scc_timer; ++i) {
    //     int x = scc_id_to_outdegree[i];
    //     cout << x << ' ';
    // }
    // cout << '\n';

    int count_with_0_outdegree = 0;
    for (int i = 0; i < scc_timer; ++i) {
        if (scc_id_to_outdegree[i] == 0) {
            if (count_with_0_outdegree > 0) {
                cout << 0 << '\n';
                return;
            }
            count_with_0_outdegree += scc_id_to_count[i];
        }
    }

    cout << count_with_0_outdegree << '\n';
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
