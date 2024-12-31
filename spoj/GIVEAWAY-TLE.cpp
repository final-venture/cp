// We need to use segtree of ordered_set rather than vector: https://codeforces.com/blog/entry/11080
// so that update can work in O(log^2 n)

// Ahh... Lovely
// Ordered_set also TLEs...
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

vector<ordered_set> seg;
vector<int> arr;

inline void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx].insert({arr[l], l});
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2 + 1, l, m);
    build(idx * 2 + 2, m + 1, r);
    seg[idx] = seg[idx * 2 + 1];
    for (auto x : seg[idx * 2 + 2])
        seg[idx].insert(x);
}

inline int query(int idx, int l, int r, int ql, int qr, int k)
{
    if (ql <= l && r <= qr)
    {
        int nn = seg[idx].size();
        auto it = seg[idx].lower_bound(make_pair(k, -1));
        if (it == seg[idx].end()) return 0;
        int cnt = seg[idx].order_of_key(*it);
        // cout << "cnt: " << cnt << '\n';
        return nn - cnt;
    }
    if (r < ql || l > qr)
    {
        return 0;
    }
    int m = (l + r) >> 1;
    int left = query(idx * 2 + 1, l, m, ql, qr, k);
    int right = query(idx * 2 + 2, m + 1, r, ql, qr, k);
    return left + right;
}

inline void update(int idx, int l, int r, int t, int v, int x)
{
    auto it = seg[idx].lower_bound(make_pair(x, t));
    seg[idx].erase(it);
    seg[idx].insert({v, t});

    if (l == r) {
        arr[l] = v;
        return;
    }
    int m = (l + r) >> 1;
    if (t <= m) {
        update(idx * 2 + 1, l, m, t, v, x);
    } else {
        update(idx * 2 + 2, m + 1, r, t, v, x);
    }
}

void solve()
{
    int n;
    cin >> n;
    arr.resize(n);
    seg.resize(4 * n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    build(0, 0, n - 1);

    int q;
    cin >> q;
    while (q--)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        --a; --b;
        if (cmd == 0)
        {
            int c;
            cin >> c;
            if (a > b) cout << 0 << '\n';
            else cout << query(0, 0, n - 1, a, b, c) << '\n';
        }
        else
        {
            update(0, 0, n - 1, a, b, arr[a]);
        }
    }
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
