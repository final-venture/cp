#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int n, m;
vector<vector<int>> adj;
vector<vector<int>> sccs;
vector<int> time_in;
vector<int> min_time;
vector<int> st;
vector<int> in_st;
int timer = 0;

void dfs(int node)
{
    if (time_in[node] != -1) return;
    st.push_back(node); in_st[node] = 1;
    min_time[node] = time_in[node] = timer++;
    for (int nei : adj[node])
    {
        dfs(nei);
        if (in_st[nei]) min_time[node] = min(min_time[node], min_time[nei]);
    }
    if (time_in[node] == min_time[node])
    {
        vector<int> cand;
        while (!st.empty())
        {
            int curr = st.back();
            st.pop_back();
            cand.push_back(curr);
            in_st[curr] = 0;
            if (curr == node)
            {
                break;
            }
        }
        sccs.push_back(cand);
    }
}

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1); time_in.resize(n + 1, -1); min_time.resize(n + 1); in_st.resize(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
    {
        dfs(i);
    }
    vector<int> ret(n + 1);
    int nn = sccs.size();
    cout << nn << '\n';
    // for (auto& scc : sccs)
    // {
    //     for (auto node : scc)
    //     {
    //         cout << node << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 0; i < nn; ++i)
    {
        int nnn = sccs[i].size();
        for (int j = 0; j < nnn; ++j)
        {
            ret[sccs[i][j]] = i + 1;
        }
    }
    for (int i = 1; i <= n; ++i) cout << ret[i] << ' ';
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
