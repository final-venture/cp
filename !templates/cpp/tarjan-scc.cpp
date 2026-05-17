#include <bits/stdc++.h>

using namespace std;

struct TarjanSCC {
    int n;
    vector<vector<int>> adj;
    vector<int> time_in, min_time, st, in_st;
    int timer;
    
    // Output variables
    vector<vector<int>> sccs; // Contains the lists of nodes in each SCC
    vector<int> scc_id;       // scc_id[i] = the ID of the SCC that node i belongs to

    // Initialize for _n nodes (0-indexed. Pass _n + 1 if using 1-indexed nodes)
    TarjanSCC(int _n) : n(_n), adj(_n), time_in(_n, 0), min_time(_n, 0), in_st(_n, 0), scc_id(_n, -1), timer(0) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int node) {
        min_time[node] = time_in[node] = ++timer;
        st.push_back(node);
        in_st[node] = 1;

        for (int nei : adj[node]) {
            if (!time_in[nei]) {
                dfs(nei);
                min_time[node] = min(min_time[node], min_time[nei]);
            } else if (in_st[nei]) {
                min_time[node] = min(min_time[node], time_in[nei]);
            }
        }

        // If node is a root node, pop the stack and form an SCC
        if (min_time[node] == time_in[node]) {
            vector<int> current_scc;
            int id = sccs.size(); // The ID for this new SCC
            
            while (true) {
                int v = st.back();
                st.pop_back();
                in_st[v] = 0;
                
                current_scc.push_back(v);
                scc_id[v] = id;
                
                if (v == node) break;
            }
            sccs.push_back(current_scc);
        }
    }

    // Call this to run the algorithm
    void build() {
        for (int i = 0; i < n; ++i) {
            if (!time_in[i]) {
                dfs(i);
            }
        }
    }
};
