#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXN = 1e6;
vector<int> tree;

void solve()
{
    int n, k;
    cin >> n >> k;
    set<set<int>> ret;
    tree.assign(5 * (MAXN + 5), 0);
    for (int i = 0; i < n; ++i) {
        set<int> cand;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            if (j == 0) {
                tree[0] = x;
                cand.insert(0);
                continue;
            }

            int idx = 0;
            while (tree[idx]) {
                if (x < tree[idx]) {
                    idx = idx * 2 + 1;
                }
                else {
                    idx = idx * 2 + 2;
                }
            }
            tree[idx] = x;
            cand.insert(idx);
        }
        for (auto x : cand) {
            tree[x] = 0;
        }
        ret.insert(cand);
    }

    cout << (long long)ret.size() << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
