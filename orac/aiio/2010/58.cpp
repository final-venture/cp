#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

int n;
vector<int> arr;
vector<int> pfx;

void solve()
{
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    pfx.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pfx[i] = pfx[i - 1] + arr[i];
    }
    for (int j = n; j >= 1; --j)
    {
        if (pfx[j] & 1)
        {
            continue;
        }
        int half = pfx[j] >> 1;
        if (*lower_bound(pfx.begin(), pfx.begin() + j, half) == half)
        {
            cout << half;
            return;
        }
    }
    cout << 0;
}

signed main()
{
#ifndef LOCAL
    freopen("nomin.txt", "r", stdin);
    freopen("nomout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
