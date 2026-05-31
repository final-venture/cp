#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// if edge is already in edge set, then print invalid
// check each column has exactly two 1's, no more, no less

void solve()
{
    set<pair<int, int>> st;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < m; ++j) {
        vector<int> uv;
        for (int i = 0; i < n; ++i) {
            if (a[i][j] == 1) {
                uv.push_back(i);   
            }
        }
        if (uv.size() != 2) {
            cout << "No" << '\n';
            return;
        }
        int u = uv[0], v = uv[1];
        if (st.find({u, v}) != st.end()) {
            cout << "No" << '\n';
            return;
        }
        
        st.insert({u, v});
        st.insert({v, u});
    }

    cout << "Yes" << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
