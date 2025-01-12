#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007

using namespace std;

struct UF {
    vector<int> par;
    vector<int> dist;
    vector<int> rank;

    UF(int n) {
        par.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
        dist.resize(n, 0);
        rank.resize(n, 0);
    }

    int find(int x) {
        if (x == par[x]) {
            return x;
        }
        int root = find(par[x]);
        dist[x] += dist[par[x]];
        return par[x] = root;
    }

    void unionn(int x1, int x2, int d) {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2) return;

        if (rank[p1] < rank[p2]) {
            par[p1] = p2;
            dist[p1] = dist[x2] - dist[x1] + d;
        } else if (rank[p2] < rank[p1]) {
            par[p2] = p1;
            dist[p2] = dist[x1] - dist[x2] - d;
        } else {
            par[p2] = p1;
            dist[p2] = dist[x1] - dist[x2] - d;
            ++rank[p1];
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    UF uf(n);
    for (int i = 0; i < m; ++i) {
        char cmd;
        int a;
        cin >> cmd >> a;
        if (cmd == 'Q') {
            int b;
            cin >> b;
            int root_a = uf.find(a);
            int root_b = uf.find(b);
            if(root_a != root_b){
                cout << "UNKNOWN" << endl;
            } else {
                int diff = uf.dist[a] - uf.dist[b];
                if(diff < 0){
                    cout << "SMALLER" << endl;
                } else if (diff == 0){
                    cout << "EQUAL" << endl;
                } else {
                    cout << "TALLER" << endl;
                }
            }
        } else {
            int b, d;
            cin >> b >> d;
            uf.unionn(a, b, d);
        }
    }
}

signed main() {
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
