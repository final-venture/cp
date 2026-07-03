#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    vector<int> scoreA(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int len = a[i].size();
        for (int j = 1; j <= len; ++j) {
            int ok = 1;
            string newS = a[i].substr(0, j);
            int l = 0;
            for (int k = 0; k < len; ++k) {
                if (a[i][k] == newS[l]) {
                    ++l;
                } else {
                    ok = 0;
                    break;
                }
                if (l >= newS.size()) {
                    l = 0;
                }
            }
            if (ok && l == 0) {
                scoreA[i] = j;
                break;
            }
        }
    }
    vector<string> b(n);
    vector<int> scoreB(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        int len = b[i].size();
        for (int j = 1; j <= len; ++j) {
            int ok = 1;
            string newS = b[i].substr(0, j);
            int l = 0;
            for (int k = 0; k < len; ++k) {
                if (b[i][k] == newS[l]) {
                    ++l;
                } else {
                    ok = 0;
                    break;
                }
                if (l >= newS.size()) {
                    l = 0;
                }
            }
            if (ok && l == 0) {
                scoreB[i] = j;
                break;
            }
        }
    }

    sort(scoreA.begin(), scoreA.end());
    sort(scoreB.begin(), scoreB.end());

    // for (int i = 0; i < n; ++i) {
    //     cerr << scoreA[i] << ' ';
    // }
    // cerr << '\n';
    // for (int i = 0; i < n; ++i) {
    //     cerr << scoreB[i] << ' ';
    // }
    // cerr << '\n';

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += (scoreA[i] - scoreB[i]) * (scoreA[i] - scoreB[i]);
    }
    cout << ret << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
