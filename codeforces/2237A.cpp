#include <bits/stdc++.h>

using namespace std;

// #define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> seen(n, false);
    for (int i = 0; i < n; ++i) {
        int minIdx = -1;
        int minHt = 10000;
        for (int j = 0; j < n; ++j) {
            if (seen[j]) {
                continue;
            }
            if (a[j] < minHt) {
                minHt = a[j];
                minIdx = j;
            }
        }
        seen[minIdx] = true;
        for (int j = minIdx; j < n; ++j) {
            if (a[j] > minHt) {
                a[j] = minHt;
                break;
            }
        }
    }
    int ret = accumulate(a.begin(), a.end(), 0);
    cout << ret << '\n';
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
