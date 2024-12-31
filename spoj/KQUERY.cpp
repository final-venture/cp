// Persistent Segment Tree
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

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

struct Node
{
    int val;
    Node* left;
    Node* right;
};

void build(Node* node, int l, int r)
{
    if (l == r)
    {
        node -> val = 0;
        return;
    }
    int m = l + (r - l) / 2;
    node -> left = new Node;
    node -> right = new Node;
    build(node -> left, l, m);
    build(node -> right, m + 1, r);
    node -> val = (node -> left -> val) + (node -> right -> val);
}

void upgrade(Node* prev, Node* curr, int l, int r, int t, int v)
{
    if (l > t || r < t)
    {
        return;
    }

    if (l == r && r == t)
    {
        curr -> val = v;
        return;
    }

    int m = l + (r - l) / 2;
    if (t <= m)
    {
        curr -> right = prev -> right;
        curr -> left = new Node;
        upgrade(prev -> left, curr -> left, l, m, t, v);
    }
    else
    {
        curr -> left = prev -> left;
        curr -> right = new Node;
        upgrade(prev -> right, curr -> right, m + 1, r, t, v);
    }
    curr -> val = (curr -> left -> val) + (curr -> right -> val);
}

int query(Node* node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return node -> val;
    }
    if (l > qr || r < ql)
    {
        return 0;
    }
    int m = l + (r - l) / 2;
    int left = query(node -> left, l, m, ql, qr);
    int right = query(node -> right, m + 1, r, ql, qr);
    return left + right;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<Node*> ver(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    vector<pair<int, int>> sorted(n);
    for (int i = 0; i < n; ++i)
    {
        sorted[i] = {arr[i], i};
    }
    sort(sorted.begin(), sorted.end());
    Node* root = new Node;
    build(root, 0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        Node* prev = (i == 0) ? root : ver[i - 1];
        Node* curr = new Node;
        int idx = lower_bound(sorted.begin(), sorted.end(), make_pair(arr[i], i)) - sorted.begin();
        upgrade(prev, curr, 0, n - 1, idx, 1);
        ver[i] = curr;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        Node* curr_l = (a == 0) ? root : ver[a - 1];
        Node* curr_r = ver[b];
        int idx = upper_bound(sorted.begin(), sorted.end(), make_pair(c, n)) - sorted.begin();
        // cout << "i " << idx << '\n';
        if (idx >= n)
        {
            cout << 0 << '\n';
            continue;
        }
        cout << query(curr_r, 0, n - 1, idx, n - 1) - query(curr_l, 0, n - 1, idx, n - 1) << '\n';
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


// Merge Sort Tree - BARELY accepted on non C++14. Use struct segtree for better time.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

vector<vector<int>> seg;
vector<int> a;

inline vector<int> merge(vector<int>& v1, vector<int>& v2)
{
    vector<int> ret;
    int n1 = v1.size(), n2 = v2.size();
    int i1 = 0, i2 = 0;
    while (i1 < n1 && i2 < n2)
    {
        if (v1[i1] <= v2[i2])
        {
            ret.push_back(v1[i1]);
            ++i1;
        }
        else
        {
            ret.push_back(v2[i2]);
            ++i2;
        }
    }

    while (i1 < n1)
    {
        ret.push_back(v1[i1]);
        ++i1;
    }

    while (i2 < n2)
    {
        ret.push_back(v2[i2]);
        ++i2;
    }
    return ret;
}

inline void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = {a[l]};
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2 + 1, l, m);
    build(idx * 2 + 2, m + 1, r);
    seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}

inline int query(int idx, int l, int r, int ql, int qr, int k)
{
    if (ql <= l && r <= qr)
    {
        int nn = seg[idx].size();
        int cnt = upper_bound(all(seg[idx]), k) - seg[idx].begin();
        return nn - cnt;
    }
    if (r < ql || l > qr)
    {
        return 0;
    }
    int m = l + (r - l) / 2;
    int left = query(idx * 2 + 1, l, m, ql, qr, k);
    int right = query(idx * 2 + 2, m + 1, r, ql, qr, k);
    return left + right;
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    seg.resize(4 * n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    build(0, 0, n - 1);

    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        cout << query(0, 0, n - 1, a, b, c) << endl;
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
