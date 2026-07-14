#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

struct UF {
    vector<int> par;
    vector<int> size;

    UF(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        size.resize(n, 1);
    }

    int find(int x) {
        if (x == par[x]) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(int x1, int x2) {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2)
            return;
        if (size[p1] > size[p2]) {
            par[p2] = par[p1];
            size[p1] += size[p2];
        }
        else {
            par[p1] = par[p2];
            size[p2] += size[p1];
        }
    }
};

const int MAXN = 2e5 + 5;

// sort P to find where each element needs to end up at
// go through each element in p, find which indices it can swap to and then unite them

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n);
    vector<int> indexOf(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        indexOf[p[i]] = i;
    }
    UF uf(n + 2);

    vector<int> seen(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (seen[i]) {
            continue;
        }

        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            if (seen[num] || num > n) {
                continue;
            }
            seen[num] = 1;

            if (num + x <= n) {
                q.push(num + x);
                uf.unite(indexOf[num], indexOf[num + x]);
            }
            if (num + y <= n) {
                q.push(num + y);
                uf.unite(indexOf[num], indexOf[num + y]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (uf.find(indexOf[i]) != uf.find(i - 1)) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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
