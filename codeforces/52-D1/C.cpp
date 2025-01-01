// Circular RMQ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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

vector<int> arr;
vector<int> seg;
vector<int> lazy;
int n;

void propagate(int idx, int l, int r)
{
    if (lazy[idx])
    {
        seg[idx] += lazy[idx];
        if (l != r)
        {
            lazy[idx * 2 + 1] += lazy[idx];
            lazy[idx * 2 + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = arr[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2 + 1, l, m);
    build(idx * 2 + 2, m + 1, r);
    seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}

int query(int idx, int l, int r, int ql, int qr)
{
    propagate(idx, l, r);
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (qr < l || r < ql)
    {
        return INT_MAX;
    }
    int m = l + (r - l) / 2;
    int left = query(idx * 2 + 1, l, m, ql, qr);
    int right = query(idx * 2 + 2, m + 1, r, ql, qr);
    return min(left, right);
}

int update(int idx, int l, int r, int ql, int qr, int v)
{
    propagate(idx, l, r);
    if (ql <= l && r <= qr)
    {
        seg[idx] += v;
        if (l != r)
        {
            lazy[idx * 2 + 1] += v;
            lazy[idx * 2 + 2] += v;
        }
        return seg[idx];
    }
    if (qr < l || r < ql)
    {
        return seg[idx];
    }
    int m = l + (r - l) / 2;
    int left = update(idx * 2 + 1, l, m, ql, qr, v);
    int right = update(idx * 2 + 2, m + 1, r, ql, qr, v);
    return seg[idx] = min(left, right);
}

int do_query(int l, int r)
{
    if (l <= r) return query(0, 0, n - 1, l, r);
    else
    {
        return min(query(0, 0, n - 1, l, n - 1), query(0, 0, n - 1, 0, r));
    }
}

void do_update(int l, int r, int v)
{
    if (l <= r) update(0, 0, n - 1, l, r, v);
    else
    {
        update(0, 0, n - 1, l, n - 1, v);
        update(0, 0, n - 1, 0, r, v);
    }
}

void solve()
{
    cin >> n;
    arr.resize(n);
    seg.resize(4 * n);
    lazy.resize(4 * n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    build(0, 0, n - 1);
    int m;
    cin >> m;
    cin.ignore();
    while (m--)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> cmd;
        int num;
        while (ss >> num)
        {
            cmd.push_back(num);
        }

        if (cmd.size() == 2)
        {
            int a = cmd[0], b = cmd[1];
            cout << do_query(a, b) << '\n';
        }
        else
        {
            int a = cmd[0], b = cmd[1], c = cmd[2];
            do_update(a, b, c);
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
