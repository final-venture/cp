#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXH = 1e6;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<set<int>> b(MAXH + 5);
    vector<int> done(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[a[i]].insert(i);
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (done[i]) {
            continue;
        }
        ++ret;
        int currVal = a[i];
        int currIdx = i;
        done[i] = 1;
        while (true) {
            auto it = b[currVal - 1].upper_bound(currIdx);
            if (it == b[currVal - 1].end()) {
                break;
            }
            currIdx = *it;
            done[currIdx] = 1;
            b[currVal - 1].erase(it);
            --currVal;
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
