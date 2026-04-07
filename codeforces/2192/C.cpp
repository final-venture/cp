#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, h, k;
    cin >> n >> h >> k;
    vector<int> a(n);
    int summ = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        summ += a[i];
    }
    int reloadTime = (h % summ == 0) ? (h / summ - 1) * k : h / summ * k;
    int shootTime = h / summ * n;
    int ret = reloadTime + shootTime;
    h %= summ;
    vector<int> sfxMax(n);
    sfxMax[n - 1] = -1;
    for (int i = n - 2; i >= 0; --i) {
        sfxMax[i] = max(a[i + 1], sfxMax[i + 1]);
    }
    int currLowest = INT_MAX;
    int currSum = 0;
    if (h <= 0) {
        cout << ret << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        currLowest = min(currLowest, a[i]);
        currSum += a[i];
        // if (i == 1) {
        //     cout << currSum << ' ' << currLowest << ' ' << sfxMax[i] << '\n';
        // }
        if (currSum >= h || currSum - currLowest + sfxMax[i] >= h) {
            cout << ret + (i + 1) << '\n';
            return;
        }
    }
    cout << a[n + 10] << '\n';
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
