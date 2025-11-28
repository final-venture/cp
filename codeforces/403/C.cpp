#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int n;
vector<int> finish;
vector<int> seen;

void dfs(int node, vector<vector<int>>& adj)
{
    if (seen[node]) return;
    seen[node] = 1;
    for (int neiNode = 0; neiNode < n; ++neiNode)
    {
        if (adj[node][neiNode])
        {
            dfs(neiNode, adj);
        }
    }
    finish.pb(node);
    return;
}

void solve()
{
    int res = 0;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    vector<vector<int>> revAdj(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> adj[i][j];
            revAdj[j][i] = adj[i][j];
        }
    }
    seen = vector<int>(n, 0);
    dfs(0, adj);
    for (int i = 0; i < n; ++i)
    {
        if (!seen[i])
        {
            res = 2;
            break;
        }
    }
    if (res != 2)
    {
        seen = vector<int>(n, 0);
        vector<int> finishCopy(finish);
        for (int i = 0; i < n; ++i)
        {
            int lastFinish = finishCopy.back();
            finishCopy.pop_back();
            if (!seen[lastFinish])
            {
                ++res;
                dfs(lastFinish, revAdj);
            }
        }
    }
    cout << ((res > 1) ? "NO" : "YES") << '\n';
}

int main()
{
    init();
    solve();
    return 0;
}
