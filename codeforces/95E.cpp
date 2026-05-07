#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9

void init() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

class UF {
private:
    vector<int> par;
    vector<int> size;

public:
    UF(int n) {
        par.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }

    int find(int x) {
        int p = par[x];
        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    void unionn(int x1, int x2) {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2) return;
        if (size[p1] > size[p2]) {
            par[p2] = par[p1];
            size[p1] += size[p2];
        } else {
            par[p1] = par[p2];
            size[p2] += size[p1];
        }
    }

    int getSz(int x) {
        return size[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    UF uf(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        uf.unionn(u, v);
    }
    vector<int> seen(n + 1, 0);
    vector<int> szCnt(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int id = uf.find(i);
        if (seen[id]) continue;
        seen[id] = 1;
        ++szCnt[uf.getSz(id)];
    }

    vector<pair<int, int>> csc; // (size, count)
    for (int i = 1; i <= n; ++i) {
        if (szCnt[i]) {
            csc.push_back({i, szCnt[i]});
        }
    }

    int nn = csc.size();
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    // Bounded Knapsack
    for (int i = 0; i < nn; i++) {
        int sz = csc[i].first;
        int cnt = csc[i].second;
        for (int k = 1; k <= cnt; k <<= 1) {
            cnt -= k;
            for (int j = n; j >= sz * k; j--) {
                dp[j] = min(dp[j], dp[j - sz * k] + k);
            }
        }
        if (cnt > 0) {
            for (int j = n; j >= sz * cnt; j--) {
                dp[j] = min(dp[j], dp[j - sz * cnt] + cnt);
            }
        }
    }

    vector<int> lucky;
    function<void(ll)> generateLucky = [&](ll num) {
        if (num > n) return;
        if (num) lucky.push_back(num);
        generateLucky(num * 10 + 4);
        generateLucky(num * 10 + 7);
    };

    generateLucky(0);

    int minn = 1e9;
    for (auto x : lucky) {
        minn = min(minn, dp[x]);
    }

    if (minn == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << minn - 1 << '\n';
    }
}

signed main() {
    init();
    solve();
    return 0;
}