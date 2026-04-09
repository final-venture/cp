#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int k, n;
    cin >> n >> k;
    string s;
    cin >> s;

    if (n == k) {
        for (int i = 0; i < n; ++i) {
            cout << '-';
        }
        cout << '\n';
        return;
    }

    int qn = 0;
    int lft = 0;
    int rgt = 0;
    for (int i = 0; i < k; ++i) {
        if (s[i] == '0') {
            ++lft;
        }
        else if (s[i] == '1') {
            ++rgt;
        }
        else if (s[i] == '2') {
            ++qn;
        }
    }
    int pl = n;

    string ret(n, '+');
    for (int i = 0; i < lft; ++i) {
        ret[i] = '-';
        --pl;
    }
    for (int i = n - 1; i >= n - rgt; --i) {
        ret[i] = '-';
        --pl;
    }

    int qnCopy = qn;
    for (int i = 0; i < n; ++i) {
        if (ret[i] != '-') {
            if (qnCopy > 0) {
                ret[i] = '?';
                --qnCopy;
            }
        }
    }
    qnCopy = qn;
    for (int i = n - 1; i >= 0; --i) {
        if (ret[i] != '-') {
            if (qnCopy > 0) {
                ret[i] = '?';
                --qnCopy;
            }
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
