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

ll maxdiff(vector<ll>& nums)
{
    int n = nums.size();
    ll maxx = 1;
    for (int i = 1; i < n; i += 2)
    {
        maxx = max(maxx, nums[i] - nums[i - 1]);
    }
    return maxx;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> cells(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> cells[i];
    }

    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    if (n % 2)
    {
        ll minn = 2e18;

        for (int i = 0; i < n; ++i)
        {
            ll tmp = cells[i];
            cells.erase(cells.begin() + i);
            minn = min(minn, maxdiff(cells));
            cells.insert(cells.begin() + i, tmp);
        }
        cout << minn << '\n';
    }
    else
    {
        cout << maxdiff(cells) << '\n';
    }
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
