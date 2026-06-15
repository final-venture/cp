#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<int> par, sz;
const int maxF = 2e5 + 5;

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
    int F;
    cin >> F;
    par.resize(maxF);
    iota(par.begin(), par.end(), 0LL);
    sz.assign(maxF, 1);
    int timer = 0;
    unordered_map<string, int> nameToId;
    while (F--) {
        string a, b;
        cin >> a >> b;
        if (nameToId.find(a) == nameToId.end()) {
            nameToId[a] = timer++;
        }
        if (nameToId.find(b) == nameToId.end()) {
            nameToId[b] = timer++;
        }
        int idA = nameToId[a], idB = nameToId[b];
        unite(idA, idB);
        cout << sz[find(idA)] << '\n';
    }
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
