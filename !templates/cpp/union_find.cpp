#include <bits/stdc++.h>

using namespace std;

struct UF {
    vector<int> par;
    vector<int> size;

    UF(int n)
    {
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
        if (p1 == p2) return;
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
