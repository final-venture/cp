#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

int n;
vector<int> indeg;
vector<int> banned;
vector<int> nxt;

void solve()
{
    cin >> n;
    indeg.resize(n + 1, 0);
    nxt.resize(n + 1, -1);
    banned.resize(n + 1, 0);
    for (int i = 1; i < n; ++i)
    {
        int x;
        cin >> x;
        ++indeg[x];
        nxt[i] = x;
    }
    queue<int> q;
    for (int i = 1; i < n; ++i)
    {
        if (!indeg[i])
        {
            q.push(i);
        }
    }
    int ret = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (!banned[node])
        {
            ++ret;
            if (nxt[node] != -1)
            {
                banned[nxt[node]] = 1;
            }
        }
        if (nxt[node] != -1)
        {
            --indeg[nxt[node]];
            if (!indeg[nxt[node]])
                q.push(nxt[node]);
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
