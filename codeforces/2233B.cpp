#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> ret(4 * n);

    int curr = 1;
    for (int i = 0; i < n; ++i) {
        ret[i] = curr++;
    }
    for (int i = n; i < 2 * n; ++i) {
        ret[i] = --curr;
    }
    curr = 2;
    for (int i = 2 * n; i < 3 * n; ++i) {
        ret[i] = curr;
        curr = curr + 1;
        if (curr == n + 1) {
            curr = 1;
        }
    }
    for (int i = 3 * n; i < 4 * n; ++i) {
        curr = curr - 1;
        if (curr == 0) {
            curr = n;
        }
        ret[i] = curr;
    }
    for (auto x : ret) {
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
