#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ret = 0;
    int currLen = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] != '#') {
            currLen = 0;
        }
        else {
            currLen++;
            ret = max(ret, currLen);
        }
    }

    cout << (ret + 1) / 2 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
