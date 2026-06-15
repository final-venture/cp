#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<int> par, sz;

int find(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = find(par[x]);
}

void unite(int x1, int x2) {
    int p1 = find(x1), p2 = find(x2);
    if (p1 == p2) {
        return;
    }
    if (sz[p1] > sz[p2]) {
        par[p2] = par[p1];
        sz[p1] += sz[p2];
    }
    else {
        par[p1] = par[p2];
        sz[p2] += sz[p1];
    }
}

void solve()
{
    int N, K;
    cin >> N >> K;
    par.resize(N + 1);
    iota(par.begin(), par.end(), 0LL);
    sz.assign(N + 1, 1);
    while (K--) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }
    for (int i = 1; i <= N / 2; ++i) {
        if (find(i) != find(N - i + 1)) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
