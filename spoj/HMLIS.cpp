// TLE. Use vector instead of map will probably pass, and struct for segtree
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9
#define MOD 1000000007

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

vector<pair<int, int>> seg;

pair<int, int> merge(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.first == p2.first)
    {
        return {p1.first, (p1.second + p2.second >= MOD) ? p1.second + p2.second - MOD : p1.second + p2.second};
    }
    return max(p1, p2);
}

pair<int, int> query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (qr < l || r < ql)
    {
        return { -1, 0};
    }
    int m = l + (r - l) / 2;
    pair<int, int> left = query(idx * 2 + 1, l, m, ql, qr);
    pair<int, int> right = query(idx * 2 + 2, m + 1, r, ql, qr);
    return merge(left, right);
}

pair<int, int> update(int idx, int l, int r, int t, pair<int, int> v)
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
    pair<int, int> left = update(idx * 2 + 1, l, m, t, v);
    pair<int, int> right = update(idx * 2 + 2, m + 1, r, t, v);
    return seg[idx] = merge(left, right);
}

void solve()
{
    int n;
    cin >> n;
    seg.resize(4 * n, {0, 1});
    vector<int> a(n);
    // cout << "xxx" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<int> sorted(a.begin(), a.end());
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> n2fi;
    for (int i = n - 1; i >= 0; --i)
    {
        n2fi[sorted[i]] = i;
    }
    unordered_map<int, int> cnt;

    for (int i = 0; i < n; ++i)
    {
        pair<int, int> alt = {0, 1};
        pair<int, int> cand = (n2fi[a[i]] > 0) ? query(0, 0, n - 1, 0, n2fi[a[i]] - 1) : alt;
        ++cand.first;
        if (cand.first >= MOD) cand.first -= MOD;
        update(0, 0, n - 1, n2fi[a[i]] + cnt[a[i]], cand);
        ++cnt[a[i]];
    }
    pair<int, int> ret = query(0, 0, n - 1, 0, n - 1);
    // for (auto [x, y] : seg) cout << x << ' ' << y << '\n';
    cout << ret.first << ' ' << ret.second << '\n';
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
