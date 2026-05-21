#include <bits/stdc++.h>

using namespace std;

#define int long long

// first, convert both adjacent tiles next to all '2' to '#',
//  then turn the '2' into '.'
// then, for every '1', if there is a '#' next to it, convert the '1' into '.'

// Now we only have '.', '#', '1', and '?'
// If '?' has '1' on both sides of it, then convert those '1' into '.', convert the '?' to '#'.
// The result is the the (count of '1') + (count of '#').

void solve() {
    int n;
    cin >> n;
    vector<char> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == '2') {
            a[i - 1] = '#';
            a[i + 1] = '#';
            a[i] = '.';
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1' && (a[i - 1] == '#' || a[i + 1] == '#')) {
            a[i] = '.';
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == '?' && a[i - 1] == '1' && a[i + 1] == '1') {
            a[i - 1] = '.';
            a[i + 1] = '.';
            a[i] = '#';
        }
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += (a[i] == '1' || a[i] == '#');
    }
    cout << ret << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
