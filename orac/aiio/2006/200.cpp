#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> all_x(n);
    vector<int> all_y(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> all_x[i] >> all_y[i];
    }
    sort(all_x.begin(), all_x.end());
    sort(all_y.begin(), all_y.end());
    int med_x = all_x[n / 2];
    int med_y = all_y[n / 2];
    cout << med_x << ' ' << med_y;
}

signed main()
{
#ifndef LOCAL
    freopen("spiesin.txt", "r", stdin);
    freopen("spiesout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
