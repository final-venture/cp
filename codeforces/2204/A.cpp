#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << n << '\n';
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
