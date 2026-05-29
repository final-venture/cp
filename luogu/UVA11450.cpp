#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int M, C;
    cin >> M >> C;
    vector<vector<int>> garm(C + 1);
    for (int i = 1; i <= C; ++i) {
        int K;
        cin >> K;
        garm[i].resize(K + 1);
        for (int j = 1; j <= K; ++j) {
            cin >> garm[i][j];
        }
    }

    vector<vector<int>> dp(C + 1, vector<int>(M + 1, 0));
    // dp[i][j] represents if we can buy up to index i of the C required garments paying a total of j
    dp[0][0] = 1;

    for (int i = 1; i <= C; ++i) {
        for (int j = 1; j <= M; ++j) {
            int sz = garm[i].size();
            for (int k = 1; k < sz; ++k) {
                int oCost = j - garm[i][k];
                if (oCost >= 0) {
                    dp[i][j] |= dp[i - 1][oCost];
                }
            }
        }
    }

    for (int j = M; j >= 1; --j) {
        if (dp[C][j] == 1) {
            cout << j << '\n';
            return;
        }
    }
    cout << "no solution" << '\n';
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
