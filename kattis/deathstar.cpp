#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    vector<int> ret(N, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            ret[i] |= a[i][j];
            ret[j] |= a[i][j];
        }
    }
    for (auto x : ret) {
        cout << x << ' ';
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
