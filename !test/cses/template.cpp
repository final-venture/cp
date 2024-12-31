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
