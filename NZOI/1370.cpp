#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

// #define LOCAL

void init()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int n, m, k;

int getDiff(string& s1, string& s2)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cnt += (s1[i] != s2[i]);
    }
    return cnt;
}

void solve()
{
    string s, e, words[100];
    int si, ei;
    vector<vector<int>> dist(100, vector<int>(100));
    vector<vector<int>> visited(105, vector<int>(105, 0));
    cin >> n >> m >> k >> s >> e;
    for (int i = 0; i < m; i++) {
        cin >> words[i];
        if (words[i] == s)
            si = i;
        else if (words[i] == e)
            ei = i;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = getDiff(words[i], words[j]);
        }
    }
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {si, k}});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int idx = pq.top().second.first;
        int remaining = pq.top().second.second;
        pq.pop();
        if (visited[idx][remaining]) continue;
        visited[idx][remaining] = 1;
        if (idx == ei)
        {
            cout << d << endl;
            return;
        }
        for (int i = 0; i < m; ++i)
        {
            if (i == idx) continue;
            int needed = dist[idx][i] - 1;
            if (remaining < needed) continue;
            pq.push({d + needed + 1, {i, remaining - needed}});
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

signed main()
{
    init();
#ifdef LOCAL
    int t;
    cin >> t;
    while (t--)
#endif
        solve();
    return 0;
}
