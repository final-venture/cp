#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int T, K;
    cin >> T >> K;
    int curr = 0;
    // compute F(i, k);
    for (int i = 2; i <= T; ++i) {
        curr = (curr + K) % i;
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
