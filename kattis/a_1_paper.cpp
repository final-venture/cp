#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n;
vector<double> wt;
vector<int> have;

double dfs(int type, int needed) {
    if (type > n) {
        if (needed == 0) {
            return 0;
        }
        return -1e18;
    }
    if (needed == 0) {
        return 0;
    }

    int usedQty = min(needed, have[type]);
    double usedTape = (needed / 2) * wt[type];

    return (usedTape + dfs(type + 1, (needed - usedQty) * 2));
}

void solve()
{
    cin >> n;
    wt.resize(n + 1);
    const double SQRT = sqrtl(2);
    wt[1] = 1.0 / sqrtl(SQRT);
    for (int i = 2; i < n + 1; ++i) {
        wt[i] = wt[i - 1] / SQRT;
    }
    // for (int i = 2; i <= n; ++i) {
        // cerr << wt[i] << ' ';
    // }
    // cerr << '\n';
    have.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> have[i];
    }
    double ret = dfs(2, 2);
    if (ret < 0) {
        cout << "impossible" << '\n';
    }
    else {
        cout << ret << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(11);
    solve();
    return 0;
}
