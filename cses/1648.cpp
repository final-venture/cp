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

vector<int> a;
vector<int> seg;

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = a[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2, l, m);
    build(idx * 2 + 1, m + 1, r);
    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

int query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (qr < l || r < ql)
    {
        return 0;
    }
    int m = l + (r - l) / 2;
    int left = query(idx * 2, l, m, ql, qr);
    int right = query(idx * 2 + 1, m + 1, r, ql, qr);
    return left + right;
}

int update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        a[l] = v;
        seg[idx] = v;
        return seg[idx];
    }
    if (l > t || r < t)
    {
        return seg[idx];
    }
    int m = l + (r - l) / 2;
    int left = update(idx * 2, l, m, t, v);
    int right = update(idx * 2 + 1, m + 1, r, t, v);
    return seg[idx] = left + right;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    a.resize(n + 1); seg.resize(4 * n + 4);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1)
        {
            update(1, 1, n, a, b);
        }
        else
        {
            cout << query(1, 1, n, a, b) << '\n';
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
