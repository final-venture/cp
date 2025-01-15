#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

int n;
vector<int> banned;
vector<int> nxt;
vector<int> st;
vector<int> seen;

void dfs(int node)
{
    if (seen[node])
        return;
    seen[node] = 1;
    if (nxt[node] != -1)
    {
        dfs(nxt[node]);
    }
    st.push_back(node);
}

void solve()
{
    cin >> n;
    nxt.resize(n + 1, -1);
    banned.resize(n + 1, 0);
    seen.resize(n + 1, 0);
    for (int i = 1; i < n; ++i)
    {
        cin >> nxt[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        dfs(i);
    }
    reverse(st.begin(), st.end());
    int ret = 0;
    for (auto node : st)
    {
        if (!banned[node])
        {
            ++ret;
            if (nxt[node] != -1)
            {
                banned[nxt[node]] = 1;
            }
        }
    }
    cout << ret;
}

signed main()
{
#ifndef LOCAL
    freopen("snurgle.in", "r", stdin);
    freopen("snurgle.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
