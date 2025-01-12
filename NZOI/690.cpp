#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007

using namespace std;

vector<int> seg;

int update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        seg[idx] = v;
        return seg[idx];
    }
    if (l > t || r < t)
    {
        return seg[idx];
    }
    int m = l + (r - l) / 2;
    int left = update(idx * 2 + 1, l, m, t, v);
    int right = update(idx * 2 + 2, m + 1, r, t, v);
    return seg[idx] = min(left, right);
}

int query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (r < ql || l > qr)
    {
        return INT_MAX;
    }
    int m = l + (r - l) / 2;
    int left = query(idx * 2 + 1, l, m, ql, qr);
    int right = query(idx * 2 + 2, m + 1, r, ql, qr);
    return min(left, right);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    seg.resize(4 * n);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        update(0, 0, n - 1, i, tmp);
    }
    while (m--)
    {
        char cmd;
        int a, b;
        cin >> cmd >> a >> b;
        if (cmd == 'Q')
        {
            cout << query(0, 0, n - 1, a, b) << '\n';
        }
        else
        {
            update(0, 0, n - 1, a, b);
        }
    }
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
