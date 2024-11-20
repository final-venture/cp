#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)

struct Node
{
    ll sum, maxSum, pfx, sfx;
};

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int n;
vector<Node> seg;
vector<int> nums;

Node merge(Node& left, Node& right)
{
    Node newNode;
    newNode.sum = left.sum + right.sum;
    newNode.maxSum = max({left.maxSum, right.maxSum, left.sfx + right.pfx});
    newNode.pfx = max(left.pfx, right.pfx + left.sum);
    newNode.sfx = max(right.sfx, left.sfx + right.sum);
    return newNode;
}

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = Node{nums[l], nums[l], nums[l], nums[l]};
        // sum, maxSum, pfx, sfx
        return;
    }
    int mid = (r + l) / 2;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    seg[idx] = merge(seg[left], seg[right]);
}

Node query(int idx, int l, int r, int ql, int qr)
{
    if (l > qr || r < ql)
    {
        Node nullNode{0, INT_MIN, INT_MIN, INT_MIN};
        return nullNode;
    }  // outside
    if (l >= ql && r <= qr) return seg[idx]; // l, r inside query
    // overlap:
    int mid = (r + l) / 2;
    Node left = query(idx * 2 + 1, l, mid, ql, qr);
    Node right = query(idx * 2 + 2, mid + 1, r, ql, qr);
    Node mergedNode = merge(left, right);
    return mergedNode;
}

void modify(int idx, int l, int r, int targ, int newVal)
{
    if (l == r && r == targ)
    {
        seg[idx] = Node{newVal, newVal, newVal, newVal};
        return;
    }
    if (l > targ || r < targ) return;
    int mid = (l + r) / 2;
    modify(idx * 2 + 1, l, mid, targ, newVal);
    modify(idx * 2 + 2, mid + 1, r, targ, newVal);
    Node left = seg[idx * 2 + 1];
    Node right = seg[idx * 2 + 2];
    seg[idx] = merge(left, right);
}

void solve()
{
    cin >> n;
    nums = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    seg = vector<Node>(4 * n);
    build(0, 0, n - 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            int ql, qr;
            cin >> ql >> qr;
            --ql; --qr;
            Node resNode = (query(0, 0, n - 1, ql, qr));
            cout << resNode.maxSum << '\n';
        }
        else
        {
            int targ, newVal;
            cin >> targ >> newVal;
            --targ;
            modify(0, 0, n - 1, targ, newVal);
        }
    }
}

int main()
{
    init();
    int t = 1;
    while (t--)
        solve();
    return 0;
}
