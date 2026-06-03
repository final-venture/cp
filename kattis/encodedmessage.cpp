#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    string s;
    cin >> s;
    int sz = s.size();
    int n = -1;
    for (int i = 0; i <= sz; ++i) {
        if (i * i == sz) {
            n = i;
            break;
        }
    }

    string ret;
    for (int j = n - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            ret.push_back(s[i * n + j]);
        }
    }
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
