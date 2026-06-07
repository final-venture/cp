#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int N, L;
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
        // absorb into p1
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
    cin >> N >> L;
    const int UF_SIZE = L + 5;

    par.resize(UF_SIZE);
    iota(par.begin(), par.end(), 0LL);
    sz.assign(UF_SIZE, 1);

    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
        int p = find(a);
        if (sz[p] > 0) {
            --sz[p];
            cout << "LADICA" << '\n';
        }
        else {
            cout << "SMECE" << '\n';
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
