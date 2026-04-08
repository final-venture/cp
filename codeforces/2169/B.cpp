#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    // ways to get stuck:
    // >________*, *_________<, >_____<, *_________*

    bool seen_left = false;
    bool seen_right = false;
    bool seen_star = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            if (seen_star) {
                cout << -1 << '\n';
                return;
            }
            seen_star = true;
        }
        else if (s[i] == '<') {
            if (seen_star || seen_right) {
                cout << -1 << '\n';
                return;
            }
            seen_left = true;
        }
        else if (s[i] == '>') {
            seen_right = true;
        }
    }

    seen_left = false;
    seen_right = false;
    seen_star = false;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '*') {
            seen_star = true;
        }
        else if (s[i] == '<') {
            seen_left = true;
        }
        else if (s[i] == '>') {
            if (seen_left || seen_star) {
                cout << -1 << '\n';
                return;
            }
            seen_right = true;
        }
    }

    int csc_lft = 0;
    int csc_rgt = 0;
    for (int i = 0; i < n && s[i] == '<'; ++i) {
        ++csc_lft;
    }
    for (int i = n - 1; i >= 0 && s[i] == '>'; --i) {
        ++csc_rgt;
    }
    int ret = max(csc_lft, csc_rgt);

    if (seen_star) {
        cout << ret + 1 << '\n';
    }
    else {
        cout << ret << '\n';
    }
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
