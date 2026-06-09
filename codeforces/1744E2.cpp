#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// express a and b in terms of their prime factorisation using trial division
// then combine them to get prime factorisation of a*b

// Let x = x' * c/x', and y = y' * c/y'
// Now, try x' = every subset of a*b's prime factorisation (it follows y' is the complement set)
// (this way, x * y is guaranteed to be divisible by a*b)
// check x is in bounds by checking c/x' * x' is in bounds.
// check y is in bounds by checking d/y' * y' is in bounds.

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    unordered_map<int, int> pfAB;
    int A = a, B = b;
    for (int i = 2; i * i <= A + 1; ++i) {
        while (A % i == 0) {
            A /= i;
            pfAB[i]++;
        }
    }
    for (int i = 2; i * i <= B + 1; ++i) {
        while (B % i == 0) {
            B /= i;
            pfAB[i]++;
        }
    }
    
    if (B > 0) {
        pfAB[B]++;
    }
    if (A > 0) {
        pfAB[A]++;
    }

    vector<pair<int, int>> pf;
    for (pair<int, int> p : pfAB) {
        pf.push_back(p);
    }

    int sz = pf.size();
    auto dfs = [&] (auto& self, int idx, int curr) {
        if (idx >= sz) {
            int xPrime = curr;
            int yPrime = a*b / xPrime;
            int x = c/xPrime * xPrime;
            int y = d/yPrime * yPrime;
            if (a < x && x <= c && b < y && y <= d) {
                cout << x << ' ' << y << '\n';
                return true;
            }
            return false;
        }
        int cnt = pf[idx].second;
        int incl = 1;
        for (int i = 0; i <= cnt; ++i) {
            if (self(self, idx + 1, curr * incl)) {
                return true;
            }
            incl *= pf[idx].first;
        }
        return false;
    };

    bool ret = dfs(dfs, 0, 1);
    if (!ret) {
        cout << -1 << ' ' << -1 << '\n';
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
