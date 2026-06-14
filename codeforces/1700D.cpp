#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n;
vector<int> v;

void solve()
{
    cin >> n;
    v.resize(n + 1);
    int maxSii = 0;
    int si = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        si += v[i];
        maxSii = max(maxSii, (si + i - 1) / i);
    }
    int q;
    cin >> q;
    int maxx = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t < maxSii) {
            cout << -1 << '\n';
            continue;
        }

        cout << (si + t - 1) / t << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
