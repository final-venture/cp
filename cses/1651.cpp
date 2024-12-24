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

int n, q;
vector<int> a;
vector<int> seg;
vector<int> lazy;

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

int query(int idx, int l, int r, int ql, int qr)
{
    if (lazy[idx])
    {
        seg[idx] += (lazy[idx] * (r - l + 1));
        if (l != r)
        {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }

    if (r < ql || l > qr)
    {
        return 0;
    }

    int mid = l + (r - l) / 2;
    int left = query(idx * 2, l, mid, ql, qr);
    int right = query(idx * 2 + 1, mid + 1, r, ql, qr);
    return left + right;
}

void update(int idx, int l, int r, int ql, int qr, int x)
{
    if (lazy[idx])
    {
        seg[idx] += (lazy[idx] * (r - l + 1));
        if (l != r)
        {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (ql <= l && r <= qr)
    {
        seg[idx] += (r - l + 1) * x;
        if (l != r)
        {
            lazy[2 * idx] += x;
            lazy[2 * idx + 1] += x;
        }
        return;
    }

    if (r < ql || l > qr)
    {
        return;
    }

    int mid = l + (r - l) / 2;
    update(idx * 2, l, mid, ql, qr, x);
    update(idx * 2 + 1, mid + 1, r, ql, qr, x);
    // We have to propagate upwards
    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

void solve()
{
    cin >> n >> q;
    a.resize(n + 1);
    seg.resize(4 * n + 4);
    lazy.resize(4 * n + 4, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--)
    {
        int cmd, a;
        cin >> cmd >> a;
        if (cmd == 1)
        {
            int b, u;
            cin >> b >> u;
            update(1, 1, n, a, b, u);
        }
        else
        {
            cout << query(1, 1, n, a, a) << '\n';
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
