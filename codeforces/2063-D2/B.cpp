#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    --l;
    --r;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    // cout << n - r << ' ' << l << '\n';
    vector<int> rgt;
    vector<int> lft;
    for (int i = l; i < n; ++i)
    {
        lft.push_back(arr[i]);
    }
    for (int i = 0; i <= r; ++i)
    {
        rgt.push_back(arr[i]);
    }
    // for (auto x : lft)
    //     cout << x << ' ';
    // cout << '\n';
    // for (auto x : rgt)
    // {
    //     cout << x << ' ';
    // }
    // cout << '\n';
    sort(lft.begin(), lft.end());
    sort(rgt.begin(), rgt.end());
    int qty = r - l + 1;
    int lftsum = accumulate(lft.begin(), lft.begin() + qty, 0ll);
    int rgtsum = accumulate(rgt.begin(), rgt.begin() + qty, 0ll);
    cout << min(lftsum, rgtsum) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
