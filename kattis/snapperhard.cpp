#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

int timer = 0;

void solve()
{
    int N, K;
    cin >> N >> K;

    int MOD = 1 << N;
    int newK = K % MOD;
    
    if (newK == MOD - 1) {
        cout << "Case #" << ++timer << ": " << "ON" << '\n';
    }
    else {
        cout << "Case #" << ++timer << ": " << "OFF" << '\n';
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
