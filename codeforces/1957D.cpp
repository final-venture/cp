#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int LOG = 32;

void solve()
{
    // 1. create pfx array - store xor pfx
    // 2. create pfx_0 array - pfx2[k][j] denotes the number of elements whose index is <= j
    //      and has xor pfx == 0 at bit k
    // 2. create pfx_1 array - pfx2[k][j] denotes the number of elements whose index is <= j
    //      and has xor pfx == 1 at bit k
    // 3. Count pfx_0[y - 1] * (pfx_0[n] - pfx_0[y - 1]) + pfx_1[y - 1] * (pfx_1[n] - pfx_1[y - 1]);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> pfx(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pfx[i] = pfx[i - 1] ^ a[i - 1];
    }

    vector<vector<int>> pfx_0(LOG, vector<int>(n + 1));
    vector<vector<int>> pfx_1(LOG, vector<int>(n + 1));
    
    for (int i = 0; i < LOG; ++i) {
        pfx_0[i][0] = 1;
        pfx_1[i][0] = 0;
    }

    for (int k = 0; k < LOG; ++k) {
        for (int j = 1; j <= n; ++j) {
            int curr_bit = (pfx[j] >> k) & 1LL;
            if (curr_bit == 0) {
                pfx_0[k][j] = pfx_0[k][j - 1] + 1;
                pfx_1[k][j] = pfx_1[k][j - 1];
            }
            else {
                pfx_0[k][j] = pfx_0[k][j - 1];
                pfx_1[k][j] = pfx_1[k][j - 1] + 1;
            }
        }
    }

    int ret = 0;
    for (int y = 1; y <= n; ++y) {
        int msb_index = -1;
        for (int i = LOG; i >= 0; --i) {
            if ((a[y - 1] >> i) & 1) {
                msb_index = i;
                break;
            }
        }

        int add_0 = pfx_0[msb_index][y - 1] * (pfx_0[msb_index][n] - pfx_0[msb_index][y - 1]);
        int add_1 = pfx_1[msb_index][y - 1] * (pfx_1[msb_index][n] - pfx_1[msb_index][y - 1]);

        ret += add_0 + add_1;
    }

    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
