// Tarjan's Algorithm - Variant 1
// As usual, we time_in and min_time arrays
// But now we also need to keep track of a stack
// which contains all the nodes we traversed through in the current dfs from the solve function
// Update min time - minimum time in of neighbours, but we have to ensure the neiNode is in the stack
// this stops interference between connected components.
// If time_in[node] == min_time[node], that marks the beginning of a connected component, as it means there is no other way to get to it
// So pop everything that we dfs'd after it, and add to array of SCCs.

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
int timer = 1;
vector<int> min_time;
vector<int> st;
vector<int> in_st;
vector<vector<int>> sccs;

void dfs(int node)
{
    if (time_in[node] != -1) return;
    time_in[node] = min_time[node] = timer++;
    st.push_back(node);
    in_st[node] = 1;

    for (int nei : adj[node])
    {
        dfs(nei);
        if (in_st[nei]) min_time[node] = min(min_time[nei], min_time[node]);
    }
    if (time_in[node] == min_time[node])
    {
        vector<int> cand;
        while (!st.empty())
        {
            int curr = st.back();
            st.pop_back();
            in_st[curr] = 0;
            cand.push_back(curr);
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

    for (int i = 1; i <= n; ++i)
    {
        dfs(i);
    }
    int nn = sccs.size();
    if (nn > 1)
    {
        cout << "NO" << '\n';
        cout << sccs[0][0] << ' ' << sccs[1][0] << '\n';
    }
    else
    {
        cout << "YES" << '\n';
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
