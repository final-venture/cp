#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    int maxIdx = 0;
    int maxVal = -1;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] > maxVal) {
            maxVal = p[i];
            maxIdx = i;
        }
    }
    swap(p[0], p[maxIdx]);
    for (auto x : p) {
        cout << x << ' ';
    }
    cout << '\n';
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
