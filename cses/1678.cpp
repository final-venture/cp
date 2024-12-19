#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
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
vector<int> st;
vector<int> inStack;
vector<int> seen;
vector<int> ret;

bool dfs(int node)
{
    st.pb(node);
    inStack[node] = 1;
    for (int nei : adj[node])
    {
        if (inStack[nei])
        {
            ret.pb(nei);
            return true;
        }
        if (!seen[nei])
        {
            seen[nei] = 1;
            if (dfs(nei)) return true;
        }
    }
    st.pop_back();
    inStack[node] = 0;
    return false;
}

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    st.resize(n + 1);
    inStack.resize(n + 1, 0);
    seen.resize(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    int ok = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!seen[i])
        {
            seen[i] = 1;
            if (dfs(i))
            {
                ok = 1;
                break;
            }
        }

    }
    if (!ok)
    {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    while (st.back() != ret[0])
    {
        ret.pb(st.back());
        st.pop_back();
    }
    ret.pb(ret[0]);
    reverse(all(ret));
    cout << ret.size() << '\n';
    for (int x : ret) cout << x << ' ';
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
