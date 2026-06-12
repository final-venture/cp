#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i - k < 0) {
            break;
        }
        if (a[i] == 1) {
            a[i] ^= 1;
            a[i - k] ^= 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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
