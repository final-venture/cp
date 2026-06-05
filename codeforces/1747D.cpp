#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> pfx(n + 1, 0);
    vector<int> zeroCnt(n + 1, 0);
    unordered_map<int, vector<int>> even, odd;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        zeroCnt[i] = zeroCnt[i - 1];
        if (a[i] == 0) {
            ++zeroCnt[i];
        }
        pfx[i] = pfx[i - 1] ^ a[i];
        if (i % 2 == 0) {
            even[pfx[i]].push_back(i);
        }
        else {
            odd[pfx[i]].push_back(i);
        }
    }

    // for (auto x : pfx) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    while (q--) {
        int l, r;
        cin >> l >> r;

        if (zeroCnt[r] - zeroCnt[l - 1] == r - l + 1) {
            cout << 0 << '\n';
            continue;
        }

        if ((pfx[r] ^ pfx[l - 1]) != 0) {
            // cout << (pfx[r] ^ pfx[l - 1]) << '\n';
            cout << -1 << '\n';
            continue;
        }

        if ((r - l + 1) & 1) {
            cout << 1 << '\n';
            continue;
        }

        // now it has to be an even subarray whose chain XOR is 0
        if (a[l] == 0 || a[r] == 0) {
            cout << 1 << '\n';
            continue;
        }

        // 0, 2, 4...
        // 1, 3, 5...
        vector<int>& toSearch = (l & 1) ? odd[pfx[l - 1]] : even[pfx[l - 1]];
        auto it = lower_bound(toSearch.begin(), toSearch.end(), l);
        if (it == toSearch.end() || (*it) >= r) {
            cout << -1 << '\n';
            continue;
        }
        else {
            cout << 2 << '\n';
            continue;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
