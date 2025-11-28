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

vector<int> seg;

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = 0;
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2 + 1, l, m);
    build(idx * 2 + 2, m + 1, r);
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
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
    int left = query(idx * 2 + 1, l, m, ql, qr);
    int right = query(idx * 2 + 2, m + 1, r, ql, qr);
    return left + right;
}

int update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        seg[idx] = 1;
        return seg[idx];
    }
    if (l > t || r < t)
    {
        return seg[idx];
    }
    int m = l + (r - l) / 2;
    int left = update(idx * 2 + 1, l, m, t, v);
    int right = update(idx * 2 + 2, m + 1, r, t, v);
    return seg[idx] = left + right;
}

void solve()
{
    int n;
    cin >> n;
    seg.resize(4 * n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    unordered_map<int, int> cnt;
    vector<int> pfx(n + 1);
    vector<int> sfx(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        ++cnt[a[i]];
        pfx[i] = cnt[a[i]];
    }
    cnt.clear();

    for (int i = n; i >= 1; --i)
    {
        ++cnt[a[i]];
        sfx[i] = cnt[a[i]];
    }
    cnt.clear();

    build(0, 0, n - 1);
    vector<int> sorted(pfx.begin() + 1, pfx.end());
    sort(sorted.begin(), sorted.end(), greater<>());

    // for (int x : sorted) cout << x << ' ';
    //     cout << '\n';
    unordered_map<int, int> n2fi;
    for (int i = 0; i < n; ++i)
    {
        if (n2fi.find(sorted[i]) != n2fi.end()) continue;
        n2fi[sorted[i]] = i;
    }

    int ret = 0;
    for (int i = 1; i <= n; ++i)
    {
        // cout << n2fi[sfx[i]] + cnt[sfx[i]] - 1 << ' ';
        // cout << n2fi[pfx[i]] + cnt[pfx[i]] << '\n';
        int add = (i == 1) ? 0 : query(0, 0, n - 1, 0, n2fi[sfx[i]] - 1);
        // cout << add << ' ';
        update(0, 0, n - 1, n2fi[pfx[i]] + cnt[pfx[i]], 1);
        ++cnt[pfx[i]];
        ret += add;
    }
    cout << ret << '\n';
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
