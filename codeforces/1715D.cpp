#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

int n, q;
vector<vector<pair<int, int>>> adj;
vector<vector<bool>> s;

const int LOG = 31;

void solve()
{
    cin >> n >> q;
    s.assign(n + 1, vector<bool>(LOG, 1));
    adj.resize(n + 1);
    for (int idx = 0; idx < q; ++idx) {
        int i, j, x;
        cin >> i >> j >> x;
        adj[i].push_back({x, j});
        adj[j].push_back({x, i});
    }

    for (int bit = 0; bit < LOG; ++bit) {
        // unset set both nodes incident to edge weights of 0.
        for (int node = 1; node <= n; ++node) {
            for (auto [neiW, neiN] : adj[node]) {
                int wt = ((neiW >> bit) & 1);
                if (wt == 0) {
                    s[node][bit] = 0;
                    s[neiN][bit] = 0;
                }
            }
        }

        // for edge weights of 1, see if we can unset a node at one of its endpoints.
        for (int node = 1; node <= n; ++node) {
            int ok = 1;
            for (auto [neiW, neiN] : adj[node]) {
                int wt = ((neiW >> bit) & 1);
                if ((wt == 1 && !s[neiN][bit]) || (neiN == node && wt == 1)) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                s[node][bit] = 0;
            }
        }
    }

    vector<int> ret(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < LOG; ++j) {
            if (s[i][j]) {
                ret[i] |= (1 << j);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ret[i] << ' ';
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
