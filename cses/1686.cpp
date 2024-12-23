#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9
#define int ll

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

class UF
{
private:
    vector<int> par;
    vector<int> rank;
public:
    UF(int n)
    {
        par.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
        rank.resize(n, 1);
    }
    int find(int x)
    {
        int p = par[x];
        while (p != par[p])
        {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    void unionn(int x1, int x2)
    {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2) return;
        if (rank[p1] > rank[p2])
        {
            par[p2] = par[p1];
        }
        else if (rank[p1] < rank[p2])
        {
            par[p1] = par[p2];
        }
        else
        {
            par[p1] = par[p2];
            ++rank[p2];
        }
    }
};


int n, m;
vector<int> dp;
vector<int> a;
vector<int> time_in;
vector<int> min_time;
vector<int> st;
vector<int> in_st;
vector<vector<int>> adj;
vector<set<int>> adj2;
vector<vector<int>> sccs;
vector<int> newVals;
int timer = 0;

void tarj(int node)
{
    if (time_in[node] != -1) return;
    // cout << "test" << endl;
    min_time[node] = time_in[node] = timer++;
    st.push_back(node); in_st[node] = 1;
    for (int nei : adj[node])
    {
        tarj(nei);
        if (in_st[nei]) min_time[node] = min(min_time[node], min_time[nei]);
    }
    if (time_in[node] == min_time[node])
    {
        vector<int> cand;
        while (!st.empty())
        {
            int x = st.back();
            st.pop_back();
            in_st[x] = 0;
            cand.push_back(x);
            if (x == node)
            {
                break;
            }
        }
        sccs.push_back(cand);
    }
}

int dfs(int node)
{
    if (dp[node] != -1) return dp[node];
    dp[node] = newVals[node];
    int add = 0;
    for (int nei : adj2[node])
    {
        // cout << nei << '\n';
        add = max(add, dfs(nei));
    }
    dp[node] += add;
    return dp[node];
}

void solve()
{
    cin >> n >> m;
    dp.resize(n + 1, -1); adj.resize(n + 1); a.resize(n + 1); adj2.resize(n + 1);
    time_in.resize(n + 1, -1); min_time.resize(n + 1); in_st.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
    {
        tarj(i);
    }

    // for (int i = 0; i < sccs.size(); ++i)
    // {
    //     for (int j = 0; j < sccs[i].size(); ++j)
    //     {
    //         cout << sccs[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    UF uf(n + 1);
    for (auto& scc : sccs)
    {
        int nn = scc.size();
        for (int i = 1; i < nn; ++i)
        {
            uf.unionn(scc[i], scc[i - 1]);
        }
    }
    newVals.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int newIdx = uf.find(i);
        newVals[newIdx] += a[i];
    }
    for (int u = 1; u <= n; ++u)
    {
        for (int v : adj[u])
        {
            int uu = uf.find(u), vv = uf.find(v);
            if (uu != vv) adj2[uu].insert(vv);
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; ++i)
    {
        ret = max(ret, dfs(i));
    }
    // for (int x : dp) cout << x << endl;
    cout << ret << '\n';
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
