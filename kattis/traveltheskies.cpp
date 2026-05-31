#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    // k = number of airports (nodes)
    // n = number of days, m = number of flights (edges)
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<int>> availDayNode(n + 2, vector<int>(k + 1, 0));
    vector<vector<vector<pair<int, int>>>> adjDayNode(n + 1, vector<vector<pair<int, int>>>(k + 1));

    for (int i = 0; i < m; ++i) {
        // d = day of flight, z = capacity
        int u, v, d, z;
        cin >> u >> v >> d >> z;
        // It is guaranteed there will be at most one flight in each direction 
        //  between any two airports on a given day.
        // each customer can only take one flight a day.
        adjDayNode[d][u].push_back({z, v});
    }

    for (int i = 0; i < k * n; ++i) {
        int a, b, c;
        // airport, day, number of people
        cin >> a >> b >> c;
        availDayNode[b][a] += c;
    }

    for (int i = 1; i <= n; ++i) {
        for (int u = 1; u <= k; ++u) {
            for (auto& [cap, v] : adjDayNode[i][u]) {
                if (cap > availDayNode[i][u]) {
                    cout << "suboptimal" << '\n';
                    return;
                }
                availDayNode[i + 1][v] += cap;
                availDayNode[i][u] -= cap;
            }
            availDayNode[i + 1][u] += availDayNode[i][u];
        }
    }

    cout << "optimal" << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
