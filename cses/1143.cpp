#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9
#define int ll

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

struct xdd
{
    int maxx;
    int idx;
};

vector<int> a;
vector<xdd> seg;

xdd merge(xdd x1, xdd x2)
{
    xdd ret;
    if (x1.maxx > x2.maxx)
    {
        ret.maxx = x1.maxx;
        ret.idx = x1.idx;
    }
    else if (x1.maxx < x2.maxx)
    {
        ret.maxx = x2.maxx;
        ret.idx = x2.idx;
    }
    else if (x1.maxx == x2.maxx)
    {
        ret.maxx = x1.maxx;
        ret.idx = (x1.idx < x2.idx) ? x1.idx : x2.idx;
    }
    return ret;
}

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = {a[l], l};
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2, l, m);
    build(idx * 2 + 1, m + 1, r);
    seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
}

int query(int idx, int l, int r, int x)
{
    if (seg[idx].maxx < x)
    {
        // cout << "RET 0: " << l << ' ' << r << '\n';
        return 0;
    }
    if (l == r)
    {
        return seg[idx].idx;
    }
    int m = l + (r - l) / 2;

    int idxx = 11111111;
    if (seg[2 * idx].maxx >= x)
    {
        idxx = query(2 * idx, l, m, x);
    }
    else
    {
        idxx = query(2 * idx + 1, m + 1, r, x);
    }
    return idxx;
}

xdd update(int idx, int l, int r, int t, int q)
{
    if (l == r && r == t)
    {
        seg[idx].maxx -= q;
        return seg[idx];
    }
    if (l > t || r < t)
    {
        return seg[idx];
    }
    int m = l + (r - l) / 2;
    xdd left = update(idx * 2, l, m, t, q);
    xdd right = update(idx * 2 + 1, m + 1, r, t, q);
    return seg[idx] = merge(left, right);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    seg.resize(4 * n + 4);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--)
    {
        int q;
        cin >> q;
        int ret = query(1, 1, n, q);
        cout << ret << ' ';
        update(1, 1, n, ret, q);
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
