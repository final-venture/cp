#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> a(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> ret(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            ret[i][j] = a[i][j] + max(ret[i - 1][j], ret[i][j - 1]);
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << ret[i][M] << ' ';
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
