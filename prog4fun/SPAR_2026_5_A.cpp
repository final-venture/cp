#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve() {
    int n, c;
    cin >> n >> c;
    int minn = 0;
    int maxx = 0;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    vector<int> ret(n);
    ret[0] = 0;
    for (int i = 1; i < n; ++i) {
        ret[i] = max({0LL, abs(x[i] - x[minn]) - c * abs(i - minn), abs(x[i] - x[maxx]) - c * abs(i - maxx)});
        if (x[minn] + c * (i - minn) > x[i]) {
            minn = i;
        }
        if (x[maxx] - c * (i - maxx) < x[i]) {
            maxx = i;
        }
    }
    for (auto xx : ret) {
        cout << xx << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
