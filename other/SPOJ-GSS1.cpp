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

Node merge(Node& n1, Node& n2)
{
    Node newNode;
    newNode.sum = n1.sum + n2.sum;
    newNode.maxSum = max({n1.maxSum, n2.maxSum, n1.sfx + n2.pfx});
    newNode.pfx = max(n1.pfx, n2.pfx + n1.sum);
    newNode.sfx = max(n2.sfx, n1.sfx + n2.sum);
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
        int ql, qr;
        cin >> ql >> qr;
        --ql; --qr;
        Node resNode = (query(0, 0, n - 1, ql, qr));
        cout << resNode.maxSum << '\n';
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
