#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> possible {1};
    int ret = 1;
    for (int i = 0; i < n; ++i) {
        if (x % a[i] != 0) {
            continue;
        }
        
        // for (auto x : possible) {
        //     cout << x << ' ';
        // }

        vector<int> nxt;
        int done = 0;
        for (auto curr : possible) {
            int cand = curr * a[i];
            if (cand == x) {
                ++ret;
                possible.clear();
                possible.insert(1);
                possible.insert(a[i]);
                done = 1;
                break;
            }
            if (x % cand != 0) {
                continue;
            }
            nxt.push_back(cand);
        }
        if (!done) {
            for (auto curr : nxt) {
                possible.insert(curr);
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
