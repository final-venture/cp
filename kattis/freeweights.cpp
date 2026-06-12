#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n;
vector<int> a1;
vector<int> a2;

bool check(int m) {
    int unclosed = -1;
    for (int i = 0; i < n; ++i) {
        if (a1[i] <= m) {
            continue;
        }
        if (unclosed == -1) {
            unclosed = a1[i];
        }
        else if (unclosed == a1[i]) {
            unclosed = -1;
        }
        else {
            return false;
        }
    }
    if (unclosed > m) {
        return false;
    }
    unclosed = -1;
    for (int i = 0; i < n; ++i) {
        if (a2[i] <= m) {
            continue;
        }
        if (unclosed == -1) {
            unclosed = a2[i];
        }
        else if (unclosed == a2[i]) {
            unclosed = -1;
        }
        else {
            return false;
        }
    }
    if (unclosed > m) {
        return false;
    }
    return true;
}

void solve()
{
    cin >> n;
    a1.resize(n); a2.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a2[i];
    }
    int l = 0, r = 2e9;
    int ret = 2e9;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            ret = m;
            r = m - 1;
        }
        else {
            l = m + 1;
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
