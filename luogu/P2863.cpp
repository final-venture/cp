#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<vector<int>> adj;
vector<int> time_in;
vector<int> min_time;
vector<int> st;
vector<int> in_st;
int ret;
int timer;

void tarjan(int node) {
    min_time[node] = time_in[node] = ++timer;
    st.push_back(node); in_st[node] = 1;

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
        int scc_sz = 0;
        while (!st.empty() && st.back() != node) {
            ++scc_sz;
            in_st[st.back()] = 0;
            st.pop_back();
        }
        ++scc_sz;
        in_st[st.back()] = 0;
        st.pop_back();
        if (scc_sz >= 2) {
            ++ret;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
    }
    st.clear();
    in_st.assign(n, 0);
    min_time.assign(n, 0);
    time_in.assign(n, 0);

    // ret is the number of sccs with size >= 2
    ret = 0;
    timer = 0;
    for (int i = 0; i < n; ++i) {
        if (!time_in[i]) {
            tarjan(i);
        }
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
