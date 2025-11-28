#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define int ll

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
    vector<int> arr(n + 1, 0);
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> arr[i];
    }
    vector<int> pfx1(n + 1, 0);
    for (int i = 1; i < n + 1; ++i)
    {
        pfx1[i] = pfx1[i - 1] + arr[i];
    }
    vector<int> pfx2(n + 1, 0);
    for (int i = 1; i < n + 1; ++i)
    {
        pfx2[i] = pfx2[i - 1] + pfx1[i];
    }
    vector<int> ls(n + 1, 0);
    ls[1] = pfx2[n];
    for (int i = 2; i < n + 1; ++i)
    {
        ls[i] = ls[i - 1] - (n - i + 2) * arr[i - 1];
    }
    for (int i = 1; i < n + 1 ; ++i)
    {
        ls[i] += ls[i - 1];
    }
    vector<int> bd;
    int j = 1;
    for (int i = 1; i < n + 1; ++i)
    {
        bd.pb(j);
        j += n - i + 1;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        int gl = upper_bound(all(bd), l) - bd.begin();
        int gr = upper_bound(all(bd), r) - bd.begin();

        int ans = ls[gr] - ls[gl - 1];

        l -= bd[gl - 1] - 1;
        ans -= pfx2[l + gl - 2] - pfx2[gl - 1] - pfx1[gl - 1] * (l - 1);
        r -= bd[gr - 1] - 1;
        ans -= pfx2[n] - pfx2[gr + r - 1] - pfx1[gr - 1] * (n - r - gr + 1);

        cout << ans << '\n';
    }
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
