#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n; 
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> retRev(n - 1);
    vector<bool> done(2001, false);
    for (int i = n - 1; i >= 1; --i) {
        // seen congruence class to index
        int c2i[2001];
        memset(c2i, -1, sizeof(c2i));
        for (int j = 0; j < n; ++j) {
            if (done[j]) {
                continue;
            }

            int cand = a[j] % i;
            if (c2i[cand] == -1) {
                c2i[cand] = j;
            }
            else {
                done[c2i[cand]] = true;
                retRev[i - 1] = {c2i[cand], j};
                break;
            }
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n - 1; ++i) {
        cout << retRev[i].first + 1 << ' ' << retRev[i].second + 1 << '\n';
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
