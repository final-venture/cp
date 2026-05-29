#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9
#define LSOne(x) (x) & (-x)

int timer = 1;
int N;
vector<int> a;
vector<int> fenw;

// query 1 to r
int query(int r) {
    int ret = 0;
    for (; r > 0; r -= LSOne(r)) {
        ret += fenw[r];
    }
    return ret;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

void update(int t, int v) {
    for (; t <= N; t += LSOne(t)) {
        fenw[t] += v;
    }
}

void solve()
{
    a.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    fenw.assign(N + 3, 0);
    for (int i = 1; i <= N; ++i) {
        update(i, a[i]);
    }

    while (true) {
        char cmd;
        cin >> cmd;
        if (cmd == 'E') {
            char garb1, garb2;
            cin >> garb1 >> garb2;
            return;
        }
        else if (cmd == 'M') {
            int x, y;
            cin >> x >> y;
            cout << query(x, y) << '\n';
        }
        else if (cmd == 'S') {
            int x, r;
            cin >> x >> r;
            int delta = r - a[x];
            a[x] = r;
            update(x, delta);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        if (timer > 1) {
            cout << '\n';
        }
        cout << "Case " << timer++ << ':' << '\n';
        solve();
    }
    return 0;
}
