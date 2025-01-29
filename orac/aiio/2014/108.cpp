#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        cnt += max(0ll, arr[i] - arr[i - 1]);
    }
    cout << cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
