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

    int cnt_2025 = 0;
    for (int i = 3; i < s.size(); ++i) {
        if (s[i - 3] == '2' && s[i - 2] == '0' && s[i - 1] == '2' && s[i] == '5') {
            ++cnt_2025;
        }
    }

    int maxDone = 0;
    for (int i = 3; i < s.size(); ++i) {
        int done = 0;
        if (s[i - 3] == '2') {
            ++done;
        }
        if (s[i - 2] == '0') {
            ++done;
        }
        if (s[i - 1] == '2') {
            ++done;
        }
        if (s[i] == '6') {
            ++done;
        }
        maxDone = max(done, maxDone);
    }
    cout << min(cnt_2025, 4 - maxDone) << '\n';
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
