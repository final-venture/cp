#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    string ret;
    for (int i = 0; i < n; ++i) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            ret.push_back(s[i]);
        }
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
