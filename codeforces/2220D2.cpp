#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n;
int a_sz;

// query from l to r, wrapping around when needed
int query(int l, int r) {
    int ret;
    int q_sz = r - l + 1;
    cout << "? " << q_sz;
    for (int i = 0; i < q_sz; ++i) {
        cout << " " << ((l + i - 1) % a_sz) + 1;
    }
    cout << endl;
    cin >> ret;

    if (ret == -1) {
        exit(0);
    }

    return ret;
}

// bs the cyclic array starting from st_idx
int bs(int st_idx) {
    int l = st_idx, r = st_idx + a_sz - 1;
    int ret = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int q_sz = m - st_idx + 1;
        int cnt = query(st_idx, m);

        if ((q_sz - cnt) % 2 == 0) {
            // the third element is in [k+1, 2n+1]
            l = m + 1;
        }
        else {
            // the third element is in [1, k]
            ret = m;
            r = m - 1;
        }
    }

    return ((ret - 1) % a_sz) + 1;
}

void solve()
{
    cin >> n;
    a_sz = 2*n+1;
    int idx3 = bs(1);
    int idx2 = bs(idx3);
    int idx1 = bs(idx2);
    cout << "! " << idx1 << " " << idx2 << " " << idx3 << endl;
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
