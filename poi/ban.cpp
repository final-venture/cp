#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9

// void init() {
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     ios::sync_with_stdio(0);
//     cin.tie(0);
// }

int b[200], c[200], dp[20001][200], dp_cnt[20001];

void solve() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    cin >> k;

    dp_cnt[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i < k + 1; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 40000;
        }
        dp_cnt[i] = 40000;
        int best = -1;

        for (int j = 0; j < n; j++) {
            if (i - b[j] < 0 || dp[i - b[j]][j] >= c[j]) continue;
            if (dp_cnt[i - b[j]] < dp_cnt[i]) {
                dp_cnt[i] = dp_cnt[i - b[j]] + 1;
                best = j;
            }
        }

        if (best != -1) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i - b[best]][j];
                if (j == best) dp[i][j]++;
            }
        }
    }

    // for (int i = 0; i < k + 1; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp_cnt[k] << '\n';
    for (int i = 0; i < n; i++) {
        cout << dp[k][i] << ' ';
    }
}

signed main() {
    // init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
