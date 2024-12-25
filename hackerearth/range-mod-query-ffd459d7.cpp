// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/range-mod-query-ffd459d7/
// Can save some time by precomputing po2.
// Just did mod_exp for fun, but turned out it was necessary for Fermat's
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9
#define int int64_t
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

vector<int> a;
vector<int> seg;
int n, q;

int mod_exp(int base, int exp)
{
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

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
    seg[idx] = ((seg[idx * 2] + seg[idx * 2 + 1]) % MOD);
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
    return (left + right) % MOD;
}

int update(int idx, int l, int r, int t)
{
    if (l == r && r == t)
    {
        a[t] = a[t] ? 0 : mod_exp(2, n - t);
        seg[idx] = a[t];
        return seg[idx];
    }
    if (l > t || r < t)
    {
        return seg[idx];
    }
    int m = l + (r - l) / 2;
    int left = update(idx * 2, l, m, t);
    int right = update(idx * 2 + 1, m + 1, r, t);
    return seg[idx] = ((left + right) % MOD);
}


void solve()
{
    cin >> n >> q;
    string s;
    cin >> s;
    a.resize(n + 1); seg.resize(4 * n + 4);
    for (int i = 1; i <= n; ++i)
    {
        if (s[i - 1] == '1')
            a[i] = mod_exp(2, n - i);
        else
            a[i] = 0;
    }
    build(1, 1, n);

    // for (auto x : a) cout << x << ' ';

    while (q--)
    {
        int cmd, a;
        cin >> cmd >> a;
        if (cmd == 2)
        {
            int b;
            cin >> b;
            int cand = query(1, 1, n, a, b);
            cand *= mod_exp(mod_exp(2, n - b), MOD - 2);
            cand %= MOD;
            cout << cand << '\n';
        }
        else
        {
            update(1, 1, n, a);
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
