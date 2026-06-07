#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int SZ = 12;

void solve()
{
    int id;
    cin >> id;
    vector<int> a(SZ);
    for (int i = 0; i < SZ; ++i) {
        cin >> a[i];
    }

    int ret = 0;
    for (int i = 1; i <= SZ - 2; ++i) {
        int minn = 1e9;
        for (int j = i; j <= SZ - 2; ++j) {
            minn = min(minn, a[j]);
            if (a[i - 1] < minn && a[j + 1] < minn) {
                ++ret;
            }
        }
    }
    cout << id << ' ' << ret << '\n';
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
