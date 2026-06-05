#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> pfxMax(n + 1, -1e13);
    for (int i = 1; i <= n; ++i) {
        pfxMax[i] = max(pfxMax[i - 1], a[i]);
    }
    vector<int> sfxMin(n + 2, 1e13);
    for (int i = n; i >= 1; --i) {
        sfxMin[i] = min(sfxMin[i + 1], a[i]);
    }

    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= pfxMax[i - 1] && a[i] < sfxMin[i + 1]) {
            ++ret;
        }
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
