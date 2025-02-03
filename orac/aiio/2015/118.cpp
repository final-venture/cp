#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll
#define MOD 1000000007

int n, m;
vector<vector<pair<int, int>>> adj;

void dijk(vector<int> &dists, vector<int> &cnt, int st)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, st});
    dists[st] = 0;
    cnt[st] = 1;
    while (!pq.empty())
    {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dists[node] < dist)
        {
            continue;
        }
        for (auto &[neiDist, neiNode] : adj[node])
        {
            if (dist + neiDist < dists[neiNode])
            {
                dists[neiNode] = dist + neiDist;
                cnt[neiNode] = cnt[node];
                pq.push({dist + neiDist, neiNode});
            }
            else if (dist + neiDist == dists[neiNode])
            {
                cnt[neiNode] += cnt[node];
                cnt[neiNode] %= MOD;
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({t, b});
        adj[b].push_back({t, a});
    }
    vector<int> distsn(n + 1, 1e18);
    vector<int> dists1(n + 1, 1e18);
    vector<int> dists2(n + 1, 1e18);
    vector<int> cntn(n + 1, 0);
    vector<int> cnt1(n + 1, 0);
    vector<int> cnt2(n + 1, 0);
    dijk(distsn, cntn, n);
    dijk(dists1, cnt1, 1);
    dijk(dists2, cnt2, 2);
    int maxDist = 0;
    int cnt = (cnt1[n] * cnt2[n]) % MOD;
    for (int i = 1; i <= n; ++i)
    {
        if (dists1[i] == dists2[i] && dists1[i] + distsn[i] == dists1[n] && dists2[i] + distsn[i] == dists2[n])
        {
            int newDist = distsn[i];
            if (newDist > maxDist)
            {
                maxDist = newDist;
                cnt = (cnt1[i] * cnt2[i] % MOD) * cntn[i];
                cnt %= MOD;
            }
            else if (newDist == maxDist && newDist != 0)
            {
                cnt += ((cnt1[i] * cnt2[i]) % MOD) * cntn[i];
                cnt %= MOD;
            }
        }
    }
    cout << maxDist << '\n';
    cout << cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
