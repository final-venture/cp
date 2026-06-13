#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, k;
    cin >> n >> k;
    string x, y;
    cin >> x; cin >> y;
    int cntx = 0, cnty = 0, cntxy = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] == '1') {
            ++cntx;
        }
        if (y[i] == '1') {
            ++cnty;
        }
        if (x[i] != y[i]) {
            ++cntxy;
        }
    }

    int currIdx = (1LL << k) + 1;
    int currL = (1LL << 1), currR = 1LL;
    vector<int> nums(4);

    while (currIdx > 1) {
        if (currIdx <= 3) {
            if (currR == (1LL << 1)) {
                nums[currIdx] = cntx;
            }
            else if (currR == 1LL) {
                nums[currIdx] = cnty;
            }
            else {
                nums[currIdx] = cntxy;
            }
        }
        currIdx = (currIdx + 1LL) / 2LL;
        currR = currR ^ currL;
    }
    nums[1] = cntx;

    int ret = 0;
    int rem = ((1LL << k) + 1) % 3;
    for (int i = 1; i <= 3; ++i) {
        ret += nums[i] * (n - nums[i]);
    }
    ret *= ((1LL << k) + 1) / 3;
    for (int i = 1; i <= rem; ++i) {
        ret += nums[i] * (n - nums[i]);
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
