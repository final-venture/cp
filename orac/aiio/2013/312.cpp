#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> seg;
vector<int> st;
vector<int> ed;

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = {st[l], ed[l]};
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2 + 1, l, m);
    build(idx * 2 + 2, m + 1, r);
    seg[idx] = {max(seg[idx * 2 + 1].first, seg[idx * 2 + 2].first), min(seg[idx * 2 + 1].second, seg[idx * 2 + 2].second)};
}

pair<int, int> query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (r < ql || l > qr)
    {
        return {INT_MIN, INT_MAX};
    }
    int m = l + (r - l) / 2;
    pair<int, int> left = query(idx * 2 + 1, l, m, ql, qr);
    pair<int, int> right = query(idx * 2 + 2, m + 1, r, ql, qr);
    return {max(left.first, right.first), min(left.second, right.second)};
}

void solve()
{
    int n, L;
    cin >> n >> L;
    seg.resize(4 * n);
    st.resize(n);
    ed.resize(n);
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        st[i] = a;
        ed[i] = b;
    }
    build(0, 0, n - 1);
    int l = 0, r = 0;
    while (r < n)
    {
        pair<int, int> p = query(0, 0, n - 1, l, r);
        // cout << l << ' ' << r << '\n';
        // cout << p.first << ' ' << p.second << '\n';
        if (p.first >= p.second)
        {
            ++l;
            while (r < n && l > r)
            {
                ++r;
            }
        }
        else
        {
            ret = max(ret, r - l + 1);
            ++r;
        }
    }
    cout << ret;
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}