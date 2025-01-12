#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    vector<int> pfx(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pfx[i] = pfx[i - 1] + arr[i];
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << pfx[b + 1] - pfx[a] << '\n';
    }
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
