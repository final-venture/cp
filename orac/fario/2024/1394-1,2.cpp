#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

int n, k;
vector<int> is_beacon;
vector<vector<int>> adj;

void solve()
{
    cin >> n >> k;
    adj.resize(n + 1);
    is_beacon.resize(n + 1);
    for (int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        is_beacon[x] = 1;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if ((k == 1 && !is_beacon[n] && !is_beacon[1]) || k == 0)
    {
        cout << 1 << '\n';
        return;
    }
    cout << 0 << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
