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

map<ll, vector<ll>> adj;
set<ll> seen;

inline void dfs(ll node)
{
    if (seen.find(node) != seen.end()) return;
    seen.insert(node);
    for (ll nei : adj[node])
    {
        dfs(nei);
    }
}

void solve()
{
    int n;
    cin >> n;
    ll nums[n + 1];
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> nums[i];
    }
    adj.clear();
    for (int i = 2; i < n + 1; ++i)
    {
        ll u = nums[i] + i - 1;
        ll v = u + i - 1;
        adj[u].pb(v);
    }
    seen.clear();
    dfs(n);
    cout << *seen.rbegin() << '\n';
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
