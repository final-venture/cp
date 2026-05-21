// O(n^2) Cheese solution

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n;
int a, b, c;
vector<int> dp;
vector<int> x;
vector<int> pfx;

int adjust(int power) {
    return a * power * power + b * power + c;
}

void solve()
{
    cin >> n;
    cin >> a >> b >> c;
    x.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    pfx.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pfx[i] = pfx[i - 1] + x[i];
    }

    dp.assign(n + 1, -1e18);
    dp[0] = 0;
    int optimal_j = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = optimal_j; j < i; ++j) {
            int cand = dp[j] + adjust(pfx[i] - pfx[j]);
            if (cand > dp[i]) {
                optimal_j = j;
                dp[i] = cand;
            }
        }
    }

    cout << dp[n] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
