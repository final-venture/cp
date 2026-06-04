#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int d;
    cin >> d;
    vector<int> a(d);
    for (int i = 0; i < d; ++i) {
        cin >> a[i];
    }
    
    int curr = 100;
    for (int i = 1; i < d; ++i) {
        if (a[i - 1] < a[i]) {
            int bought = min(100000LL, curr / a[i - 1]);
            int rem = curr - bought * a[i - 1];
            curr = bought * a[i] + rem;
        }
    }
    cout << curr << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
