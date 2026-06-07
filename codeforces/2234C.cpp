#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    // go through all scenarios of each vessel being 0
    // then simulate O(n)
    // For each vessel i that is 0, set w_i = 0.
    // Then, 

    // decreasing, or even sequence creates a cascading effect

    // for two direct neighbours of i, we dont want water to flow into the vessel with 0 (i)
    // so we have to constrain them vessel i - 1 by min(h[i], h[i - 1]).
    // we also constrain vessel i + 1 by min(h[i], h[i + 1])

    // we only care about two direct neighbours of i, as well as any increasing/flat areas
    //  which can funnel water to them.

    // for the rest of the vessels, ret[i] = min()

    // i = 2
    // 1 2 3 4
    // 1 2 2 
    // 1 0 2 3
    // 

    // i = 3
    // 1 2 3 4 <- og array
    // 2 2 3 3 <- constraints
    // 2 2 0 3
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // i is empty
    for (int i = 0; i < n; ++i) {
        int summ = 0;
        vector<int> ret1(n), ret2(n);
        ret1[i] = 0;
        ret2[i] = 0;
        for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
            ret1[j] = max(a[(j - 1 + n) % n], ret1[(j - 1 + n) % n]);
        }
        for (int j = (i - 1 + n) % n; j != i; j = (j - 1 + n) % n) {
            ret2[j] = max(a[j], ret2[(j + 1) % n]);
        }
        for (int j = 0; j < n; ++j) {
            summ += min(ret1[j], ret2[j]);
        }
        cout << summ << ' ';
    }
    cout << '\n';
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
