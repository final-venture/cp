#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int ret = 1e9;
    int currLines = 0;
    int currTime = 0;

    // no ai
    while (currLines < n) {
        currLines += x;
        currLines += y;
        ++currTime;
    }
    ret = min(ret, currTime);

    // yes ai
    currTime = 0;
    currLines = 0;
    while (currLines < n) {
        if (currTime >= z) {
            currLines += 10 * y;
        }
        currLines += x;
        ++currTime;
    }
    ret = min(ret, currTime);
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
