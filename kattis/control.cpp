#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXM = 5e5;

struct UF {
    vector<int> par;
    vector<int> size;

    UF(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0LL);
        size.assign(n, 1);
    }

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

        if (size[p1] > size[p2]) {
            par[p2] = par[p1];
            size[p1] += size[p2];
        }
        else {
            par[p1] = par[p2];
            size[p2] += size[p1];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

void solve()
{
    int N;
    cin >> N;
    UF uf(MAXM + 5);
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        // if the ingredient is not in a cauldron (size 1), we can use it
        // list out the unique parents we find, compute the sum of their size.
        // if this sum is equal to M, then we merge all.
        vector<int> reps;
        for (int j = 0; j < M; ++j) {
            int ing;
            cin >> ing;
            reps.push_back(uf.find(ing));
        }
        sort(reps.begin(), reps.end());
        reps.erase(unique(reps.begin(), reps.end()), reps.end());
        int totalSz = 0;
        for (int j = 0; j < reps.size(); ++j) {
            totalSz += uf.getSize(reps[j]);
        }
        if (totalSz == M) {
            ++ret;
            for (int j = 1; j < reps.size(); ++j) {
                uf.unite(reps[j - 1], reps[j]);
            }
        }
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
