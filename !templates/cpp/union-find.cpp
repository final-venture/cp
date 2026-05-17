#include <bits/stdc++.h>

using namespace std;

struct UF {
    vector<int> par;
    vector<int> rank;

    UF(int n) {
        par.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
        rank.resize(n, 1);
    }

    int find(int x) {
        if (x == par[x]) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(int x1, int x2) {
        int p1 = find(x1);
        int p2 = find(x2);
        
        if (p1 == p2) return;

        if (rank[p1] > rank[p2]) {
            par[p2] = p1; // Fixed: p2 points to the root p1
        } else if (rank[p1] < rank[p2]) {
            par[p1] = p2; // Fixed: p1 points to the root p2
        } else {
            par[p1] = p2;
            ++rank[p2];
        }
    }
};
