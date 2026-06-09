#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXN = 1e6 + 5;
int fenw[MAXN];
int a[MAXN];

void update(int idx, int val) {
    a[idx] = max(0LL, val);
    for (; idx < MAXN; idx += ((idx) & (-idx))) {
        fenw[idx] += val;
    }
}

int query(int idx) {
    int ret = 0;
    for (; idx > 0; idx -= ((idx) & (-idx))) {
        ret += fenw[idx];
    }
    return ret;
}

void solve()
{
    int N, K;
    cin >> N >> K;
    memset(a, 0, sizeof(a));
    memset(fenw, 0, sizeof(fenw));
    while (K--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'F') {
            int bit; cin >> bit;
            if (a[bit]) {
                update(bit, -1);
            }
            else {
                update(bit, 1);
            }
        }
        else if (cmd == 'C') {
            int l, r;
            cin >> l >> r;
            cout << (query(r) - query(l - 1)) << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
