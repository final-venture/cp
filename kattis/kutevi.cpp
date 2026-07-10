#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector<int> b(K);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < K; ++i) {
        cin >> b[i];
    }
    vector<int> reach(360, 0);
    reach[0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 360; ++j) {
            if (reach[j]) {
                int now = j;
                for (int k = 0; k < 360; ++k) {
                    reach[now % 360] = 1;
                    now += a[i];
                }
            }
        }
    }
    for (int i = 0; i < K; ++i) {
        if (reach[b[i]]) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
