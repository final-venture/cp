#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    vector<int> diffs(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int req;
        cin >> req;
        diffs[i] = req - arr[i];
        if (diffs[i] > 0)
        {
            ++cnt;
        }
    }
    if (cnt == 0)
    {
        cout << "YES" << '\n';
        return;
    }
    if (cnt > 1)
    {
        cout << "NO" << '\n';
        return;
    }
    sort(diffs.begin(), diffs.end());
    int maxx = diffs[n - 1];
    int min_neg = diffs[n - 2];
    if (maxx + min_neg > 0)
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';
    }
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
