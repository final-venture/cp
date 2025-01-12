#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007

using namespace std;

struct Node
{
    int minn, maxx;
};

vector<Node> seg(800020, {INT_MAX, INT_MIN});
vector<int> arr;

Node merge(Node n1, Node n2)
{
    return {min(n1.minn, n2.minn), max(n1.maxx, n2.maxx)};
}

void update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        arr[v] = t;
        seg[idx] = {v, v};
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

Node query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (r < ql || l > qr)
    {
        return {INT_MAX, INT_MIN};
    }
    int m = l + (r - l) / 2;
    Node left = query(idx * 2 + 1, l, m, ql, qr);
    Node right = query(idx * 2 + 2, m + 1, r, ql, qr);
    return merge(left, right);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        update(0, 1, n, x, i);
    }

    // for (int x : arr) cout << x << ' ';
    while (m--)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1)
        {
            int tmp1 = arr[b];
            int tmp2 = arr[a];
            update(0, 1, n, tmp1, a);
            update(0, 1, n, tmp2, b);
        }
        else
        {
            Node cand = query(0, 1, n, a, b);
            // for (int x : arr) cout << x << ' ';
            // cout << '\n';
            if (cand.maxx - cand.minn <= b - a)
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
