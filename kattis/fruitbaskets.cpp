#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// For simplicity, you may assume that all fruits of the same kind weigh the same. 
// You also know that all fruits weigh at least 50 grams.
// This means every basket with >= 4 fruits will be valid.
// Need to brute every basket with < 3 fruits

int N;
vector<int> a;

int dfs(int idx, int summ) {
    if (summ >= 200) {
        return 0;
    }
    if (idx >= N) {
        return summ;
    }
    int take = dfs(idx + 1, summ + a[idx]);
    int notTake = dfs(idx + 1, summ);
    return take + notTake;
}

void solve()
{
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int full = 0;
    for (int i = 0; i < N; ++i) {
        full += a[i] * (1LL << (N - 1));
    }
    int sub = dfs(0, 0);

    cout << (full - sub) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
