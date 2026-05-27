#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXN = 20000;
const int MAXM = 20000;

int n, m;

void solve()
{
    vector<int> dia(n);
    multiset<int> knights;

    for (int i = 0; i < n; ++i) {
        cin >> dia[i];
    }
    sort(dia.begin(), dia.end(), greater<>());
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        knights.insert(x);
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        auto it = knights.lower_bound(dia[i]);
        if (it == knights.end()) {
            cout << "Loowater is doomed!" << '\n';
            return;
        }
        ret += (*it);
        knights.erase(it);
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        solve();
    }
    return 0;
}
