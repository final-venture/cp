#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9
#define LSOne(x) ((x) & (-x))

// stack = [1,2,3,4,5]
// move 4 to top
// stack = [4,1,2,3,5]

const int MAXR = 1e5 + 5;
const int MAXM = 1e5 + 10;
int fenw[MAXR + MAXM];
int mp[MAXM];

void update(int idx, int delta) {
    for (; idx < MAXR + MAXM; idx += LSOne(idx)) {
        fenw[idx] += delta;
    }
}

int query(int idx) {
    int ret = 0;
    for (; idx > 0; idx -= LSOne(idx)) {
        ret += fenw[idx];
    }
    return ret;
}

void solve() {
    int m, r;
    cin >> m >> r;

    // memset(fenw, 0, sizeof(fenw));
    // memset(mp, 0, sizeof(mp));

    iota(mp + 1, mp + m + 1, MAXR + 1);
    for (int i = 1; i <= m; ++i) {
        update(mp[i], 1);
    }
    int curr = MAXR;
    while (r--) {
        int x;
        cin >> x;
        cout << query(mp[x] - 1) << ' ';
        update(mp[x], -1);
        mp[x] = curr--;
        update(mp[x], 1);
    }
    cout << '\n';
    for (int i = 1; i <= m; ++i) {
        update(mp[i], -1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
