#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9
#define LSOne(x) ((x) & (-x))

vector<int> fenw;
const int MAXV = 1e5;

void update(int idx, int val) {
    for (; idx < MAXV + 3; idx += LSOne(idx)) {
        fenw[idx] += val;
    }
}

int query(int idx) {
    int ret = 0;
    for (; idx > 0; idx -= LSOne(idx)) {
        ret += fenw[idx];
    }
    return ret;
}

void solve()
{
    int N;
    cin >> N;
    vector<int> orig(N);
    vector<int> targ(N);
    for (int i = 0; i < N; ++i) {
        cin >> orig[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> targ[i];
    }
    fenw.assign(MAXV + 5, 0);

    int invO = 0;
    for (int i = 0; i < N; ++i) {
        invO += query(orig[i] - 1);
        update(orig[i], 1);
    }

    fenw.assign(MAXV + 5, 0);

    int invT = 0;
    for (int i = 0; i < N; ++i) {
        invT += query(targ[i] - 1);
        update(targ[i], 1);
    }

    if ((invO % 2) == (invT % 2)) {
        cout << "Possible" << '\n';
    }
    else {
        cout << "Impossible" << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
