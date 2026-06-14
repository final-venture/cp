#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
        p[i] *= 2;
        p[i] *= p[i];
    }
    vector<int> h(M + K);
    for (int i = 0; i < M; ++i) {
        cin >> h[i];
        h[i] *= 2;
        h[i] *= h[i];
    }
    for (int i = M; i < M + K; ++i) {
        cin >> h[i];
        h[i] *= h[i];
        h[i] *= 2;
    }
    sort(p.begin(), p.end(), greater<>());
    sort(h.begin(), h.end(), greater<>());

    // for (auto x : p) {
    //     cout << x << ' ';
    // }
    // cout << '\n';
    // for (auto x : h) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    int i = 0;
    int j = 0;
    int ret = 0;
    while (i < N && j < M + K) {
        while (j < M + K && p[i] <= h[j]) {
            ++j;
        }
        if (j < M + K) {
            ++ret;
            ++j;
            ++i;
        }
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
