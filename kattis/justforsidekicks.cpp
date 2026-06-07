#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9
#define LSOne(x) ((x) & (-x))

struct Fenwick {
    vector<int> fenw;
    int n;

    Fenwick (int nn) : n(nn) {
        fenw.assign(n + 5, 0);
    }
    
    int query(int idx) {
        int ret = 0;
        for (; idx > 0; idx -= LSOne(idx)) {
            ret += fenw[idx];
        }
        return ret;
    }

    void update(int idx, int val) {
        for (; idx <= n; idx += LSOne(idx)) {
            fenw[idx] += val;
        }
    }
};

void solve()
{
    int N, Q;
    cin >> N >> Q;

    // value of each type of gem
    vector<int> V(7);
    for (int i = 1; i <= 6; ++i) {
        cin >> V[i];
    }
    string s;
    cin >> s;

    // store count for each gem up to index i
    vector<Fenwick> fenw(7, Fenwick(N));

    // type of each of the N gems
    vector<int> P(N + 1);
    for (int i = 1; i <= N; ++i) {
        P[i] = s[i - 1] - '0';
        fenw[P[i]].update(i, 1);
    }

    // for (auto x : P) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    for (int it = 0; it < Q; ++it) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int k, p;
            cin >> k >> p;
            fenw[P[k]].update(k, -1);
            P[k] = p;
            fenw[p].update(k, 1);
        }
        else if (cmd == 2) {
            int p, v;
            cin >> p >> v;
            V[p] = v;
        }
        else if (cmd == 3) {
            int l, r;
            cin >> l >> r;

            int ret = 0;
            for (int i = 1; i <= 6; ++i) {
                ret += V[i] * (fenw[i].query(r) - fenw[i].query(l - 1));
            }

            cout << ret << '\n';
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
