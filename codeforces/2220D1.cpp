#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n;
vector<int> found;

int query(int l, int r) {
    int ret;
    int q_sz = r - l + 1;
    cout << "? " << q_sz;
    for (int i = l; i <= r; ++i) {
        cout << " " << i;
    }
    cout << endl;
    cin >> ret;
    if (ret == -1) {
        exit(0);
    }
    return ret;
}

int bs(int l, int r) {
    int ret = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;

        // left partition is [l, m]
        int q_l = query(1, m);
        
        // right partition is [m + 1, r]
        int q_r = query(m + 1, 2*n + 1);

        int cnt_l = 0, cnt_r = 0;
        if (q_l < q_r) {
            cnt_r = 1;
            cnt_l = 2;
        }
        else if (q_r < q_l) {
            cnt_r = 2;
            cnt_l = 1;
        }
        else if (q_l == q_r) {
            int sz_l = m;
            if ((sz_l - q_l) % 2 == 0) {
                cnt_l = 0;
                cnt_r = 3;
            }
            else {
                cnt_l = 3;
                cnt_r = 0;
            }
        }

        for (int i = 0; i < 3; ++i) {
            if (1 <= found[i] && found[i] <= m) {
                --cnt_l;
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (m + 1 <= found[i] && found[i] <= 2*n + 1) {
                --cnt_r;
            }
        }

        if (cnt_l > 0) {
            r = m - 1;
            ret = m;
        }
        else {
            l = m + 1;
        }
    }
    return ret;
}

void solve()
{
    cin >> n;
    found.assign(3, -1);
    found[0] = bs(1, 2*n + 1);
    found[1] = bs(1, 2*n + 1);
    found[2] = bs(1, 2*n + 1);
    cout << "!";
    for (int i = 0; i < 3; ++i) {
        cout << ' ' << found[i];
    }
    cout << endl;
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
