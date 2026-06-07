#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n, m;
vector<int> mp;
vector<int> par, sz, summ;
int curr;

int find(int x) {
    if (x == par[x]) {
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
        summ[p1] += summ[p2];
    }
    else {
        par[p1] = par[p2];
        sz[p2] += sz[p1];
        summ[p2] += summ[p1];
    }
}

// move x1 to x2
void move(int x1, int x2) {
    int p1 = find(mp[x1]), p2 = find(mp[x2]);
    if (p1 == p2) {
        return;
    }
    sz[p1]--;

    // sz[p2]++;
    summ[p1] -= x1;
    // summ[p2] += x1;
    // map x1 to a new node mp[x1], which will be connected to the set x2
    mp[x1] = curr++;
    // cout << curr << '\n';
    // if (p1 == mp[x1]) {
    //     cout << "FDAHJL";
    // }
    summ[mp[x1]] = x1;

    // cout << x1 << ' ' << summ[mp[x1]] << ' ' << par[mp[x1]] << ' ' << sz[mp[x1]] << '\n';
    unite(mp[x1], mp[x2]);
}

void solve()
{
    while (cin >> n >> m) {
        curr = n + 10;
        const int UF_SIZE = n + m + 20;
        mp.resize(UF_SIZE);
        iota(mp.begin(), mp.end(), 0LL);

        par.resize(UF_SIZE);
        iota(par.begin(), par.end(), 0LL);

        sz.assign(UF_SIZE, 1LL);

        summ.resize(UF_SIZE);
        iota(summ.begin(), summ.end(), 0LL);

        // {1}, {2}, {3}, {4}, {5}
        // {1, 2}, {3}, {4}, {5}
        // print set 1
        // {1, 2}, {3, 4}, {5}
        // print set 3
        // {1, 2}, {3, 4, 5}
        // {1, 2, 3}, {4, 5}
        // {2, 3}, {1, 4, 5}
        // {2}, {1, 3, 4, 5}
        // print set 4
        // print set 2

        for (int i = 0; i < m; ++i) {
            int cmd;
            cin >> cmd;
            if (cmd == 1) {
                // union set p and set q
                int p, q;
                cin >> p >> q;
                unite(mp[p], mp[q]);
            }
            else if (cmd == 2) {
                // move p to set q
                int p, q;
                cin >> p >> q;
                move(p, q);
            }
            else if (cmd == 3) {
                // output size and sum of p
                int p;
                cin >> p;
                cout << sz[find(mp[p])] << ' ' << summ[find(mp[p])] << '\n';
            }
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
