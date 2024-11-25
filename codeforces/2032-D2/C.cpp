#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
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

void solve()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    int r = 1;
    int res = n;
    for (int l = 1; l < n; ++l)
    {
        int target = nums[l] + nums[l-1];
        while (r < n && nums[r] < target) ++r;
        res = min(res, n - r + l - 1);
    }
    cout << res << '\n';
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
