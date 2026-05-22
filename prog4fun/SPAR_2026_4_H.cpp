#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// We want total ways to colour the tree with ALL k colours such that no two adjacent nodes have same colour.
// Use inclusion exclusion, don't forget the binomial coefficients.

// The answer is equal to:
// (total ways to colour the tree with SOME of the k colours such that no two adjacent nodes have same colour)
// - (total ways to colour the tree with SOME of (k - 1) colours such that no two adjacent nodes have same colour)
// + (total ways to colour the tree with SOME of (k - 2) colours such that no two adjacent nodes have same colour)
// - ... + ...

const int MOD = 1000000007;
constexpr int MAXN = 2510;
int C[MAXN][MAXN];

void build_nCr() {
    for (int j = 1; j < MAXN; ++j) {
        // 0 choose anything is 0, except 0 itself, handled later
        C[0][j] = 0;
    }
    for (int i = 0; i < MAXN; ++i) {
        C[i][0] = 1;
    }
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j < MAXN; ++j) {
            // exclude bob, we have C(i - 1, j)
            // include bob, we have C(i - 1, j - 1)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= MOD;
        }
    }
}

void solve() {
    build_nCr();
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
    }

    int ret = k;
    for (int i = 1; i < n; ++i) {
        ret *= (k - 1);
        ret %= MOD;
    }

    int toSubtract = 0;
    int positive = 1;
    for (int i = k - 1; i >= 2; --i) {
        int binomial = C[k][i];
        int contribution = i * positive;
        for (int j = 1; j < n; ++j) {
            contribution *= (i - 1);
            contribution %= MOD;
        }
        toSubtract += (binomial * contribution) % MOD;
        toSubtract %= MOD;
        positive *= -1;
    }

    cout << (ret + MOD - toSubtract) % MOD << '\n';
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
