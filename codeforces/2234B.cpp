#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

bool check(int x) {
    string xStr = to_string(x);
    int sz = xStr.size();
    for (int i = 0; i <= sz / 2; ++i) {
        if (xStr[i] != xStr[sz - i - 1]) {
            return false;
        }
    }
    return true;
}

// 12, 24, 36, 48, 60, 72, 84, 96, 106, 118, 130
// 22, 34, 46, 58, 70, 82, 94, 106, 116, 128, 140

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i <= 22; ++i) {
        if (i == 10 || (i >= 12 && i <= 21)) {
            continue;
        }
        if ((n - i) >= 0 && (n - i) % 12 == 0) {
            cout << i << ' ' << n - i << '\n';
            return;
        }
    }

    for (int i = 12; i <= 12 * 100; i += 12) {
        if (n - i >= 0 && check(n - i)) {
            cout << n - i << ' ' << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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
