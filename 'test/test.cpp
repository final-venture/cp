#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

const ll ninf = -1e18;

struct Data
{
    ll s1, s2, maxx;
};

vector<Data> seg;
vector<pair<int, int>> q_l;

Data merge(Data &d1, Data &d2)
{
    Data ret;
    ret.s1 = d1.s1 + d2.s1;
    ret.s2 = d1.s2 + d2.s2;
    ret.maxx = max(d1.maxx, d2.maxx + d1.s1 - d1.s2);
    return ret;
}

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = {q_l[l].first, q_l[l].second, q_l[l].first};
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2 + 1, l, m);
    build(idx * 2 + 2, m + 1, r);
    seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}

void update(int idx, int l, int r, int t, Data v)
{
    if (l == r && r == t)
    {
        seg[idx] = v;
        return;
    }
    if (l > t || r < t)
    {
        return;
    }
    int m = l + (r - l) / 2;
    update(idx * 2 + 1, l, m, t, v);
    update(idx * 2 + 2, m + 1, r, t, v);
    seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}

Data query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (r < ql || l > qr)
    {
        return {0, 0, ninf};
    }
    int m = l + (r - l) / 2;
    Data left = query(idx * 2 + 1, l, m, ql, qr);
    Data right = query(idx * 2 + 2, m + 1, r, ql, qr);
    return merge(left, right);
}

void solve()
{
    int n;
    cin >> n;
    q_l.resize(n);
    seg.resize(4 * n);
    for (int i = 0; i < n; ++i)
    {
        cin >> q_l[i].first >> q_l[i].second;
    }
    int sum_qty = 0;
    int sum_limit = 0;
    int min_limit = 1e17;
    for (int i = 0; i < n; ++i)
    {
        sum_qty += q_l[i].first;
        sum_limit += q_l[i].second;
        min_limit = min(min_limit, q_l[i].second);
    }
    int diff = sum_limit - sum_qty;
    if (diff < min_limit)
    {
        cout << -1 << '\n';
        return;
    }

    sort(q_l.begin(), q_l.end(), [](pair<int, int> &p1, pair<int, int> &p2)
         {
        int tp1 = (p1.first < p1.second) ? 1 : (p1.first == p1.second ? 2 : 3);
        int tp2 = (p2.first < p2.second) ? 1 : (p2.first == p2.second ? 2 : 3);
        if (tp1 != tp2) return tp1 < tp2;
        if (tp1 == 1 || tp1 == 2) return p1.first < p2.first;
        return p1.second > p2.second; });

    build(0, 0, n - 1);
    // for (auto [x, y, z] : seg)
    // {
    //     cout << x << ' ' << y << ' ' << z << '\n';
    // }
    int ret = 2e18;
    for (int i = 0; i < n; ++i)
    {
        if (sum_limit - q_l[i].second < sum_qty)
        {
            continue;
        }
        update(0, 0, n - 1, i, {0, 0, ninf});
        // for (auto [x, y, z] : seg)
        // {
        //     cout << x << ' ' << y << ' ' << z << '\n';
        // }
        Data cand = query(0, 0, n - 1, 0, n - 1);
        ret = min(ret, cand.maxx + sum_qty);
        update(0, 0, n - 1, i, {q_l[i].first, q_l[i].second, q_l[i].first});
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
