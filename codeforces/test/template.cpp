#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)

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
vector<pair<int, int>> seg;
vector<int> nums;

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = {nums[l], nums[l]};
        return;
    }
    int mid = (r + l) / 2;
    build(idx * 2 + 1, l, mid);
    build(idx * 2 + 2, mid + 1, r);
    seg[idx].first = seg[idx * 2 + 1].first + seg[idx * 2 + 2].first;
    seg[idx].second = max({seg[idx].first,
                           seg[idx * 2 + 1].second, seg[idx * 2 + 2].second
                          });
}

int query(int idx, int l, int r, int ql, int qr)
{
    if (l > qr || r < ql) return INT_MIN;    // outside
    if (l >= ql && r <= qr) return seg[idx].second; // l, r inside query
    // overlap:
    int mid = (r + l) / 2;
    int left = query(idx * 2 + 1, l, mid, ql, qr);
    int right = query(idx * 2 + 2, mid + 1, r, ql, qr);
    return max(left, right);
}

void solve()
{
    cin >> n;
    nums = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    seg = vector<pair<int, int>>(4 * n);
    build(0, 0, n - 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int ql, qr;
        cin >> ql >> qr;
        --ql; --qr;
        int res = query(0, 0, n - 1, ql, qr);
        cout << res << '\n';
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
