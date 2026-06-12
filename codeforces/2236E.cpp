#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

const int MAXA = 6000 + 5;

int can[MAXA][MAXA];

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int l = 0; l < n; ++l) {
        int currMin = a[l], currMax = a[l];
        vector<int> seen(n + 2, 0);

        for (int r = l; r < n; ++r) {
            if (seen[a[r]]) {
                break; 
            }
            seen[a[r]] = true;

            currMin = min(currMin, a[r]);
            currMax = max(currMax, a[r]);

            if (currMax - currMin == r - l) {
                can[currMin][currMax] = 1;
            }
        }
    }

    // for (int i = 1; i < 9; ++i) {
    //     for (int j = 1; j < 9; ++j) {
    //         cerr << can[i][j] << ' ';
    //     }
    //     cerr << '\n';
    // }

    int ret = 0;
    for (int i = 1; i < n + 2; ++i) {
        for (int j = 1; j < n + 2; ++j) {
            // cerr << can[i][j] << ' ';
            int len = j - i;
            // if (i == 1 && j == 1) {
            //     cout << can[i][j] << ' ' << can[j + 1][j + 1 + len];
            //     cout << '\n';
            //     cout << '\n';
            // }
            if (j + 1 + len < MAXA && can[i][j] && can[j + 1][j + 1 + len]) {
                ret = max(len + 1, ret);
            }
        }
        // cerr << '\n';
    }

    for (int i = 0; i < n + 5; ++i) {
        for (int j = 0; j < n + 5; ++j) {
            can[i][j] = 0;
        }
    }

    cout << ret << '\n';
}

signed main()
{
    memset(can, 0, sizeof(can));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
