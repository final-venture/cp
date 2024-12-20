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
vector<int> time_in;
int time = 1;
vector<int> min_time;
vector<int> st;
vector<int> in_st;
vector<vector<int>> sccs;

void dfs(int node)
{
    if (time_in[node]) return;
    st.push(node);
    in_st[node] = 1;
    time_in[node] = time;
    min_time[node] = time;
    ++time;
    for (int nei : adj[node])
    {
        dfs(nei);
        if (in_st[nei]) min_time[nei] = min(min_time[nei], min_time[node]);
    }
}

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    time_in.resize(n + 1, -1);
    min_time.resize(n + 1);
    in_st.resize(n + 1, 0);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
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
