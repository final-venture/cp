#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

int w, h;
int house_x, house_y;
int n;
vector<pair<int, int>> arr(n);
unordered_set<int> all_dirs;

const int zero_pos = 250250;
const int bound = 260000 * 2;
const int inf = 1e9;

int getBest(int st, int mult)
{
    // int nn = all_dirs.size();
    vector<int> dp(bound, inf);
    dp[zero_pos + st] = 0;

    for (auto chg : all_dirs)
    {
        if (chg < 0)
        {
            for (int i = bound - 1; i >= 0; --i)
            {
                if (i - chg < bound)
                {
                    dp[i] = min(dp[i - chg] + 1, dp[i]);
                }
            }
        }
        else if (chg > 0)
        {
            for (int i = 0; i < bound; ++i)
            {
                if (i - chg >= 0)
                {
                    dp[i] = min(dp[i - chg] + 1, dp[i]);
                }
            }
        }
    }

    // for (int i = 250222; i < 250277; ++i)
    // {
    //     cout << dp[i] << ' ';
    // }

    int ret = inf;
    for (int i = zero_pos; i < bound; i += mult)
    {
        ret = min(ret, dp[i]);
    }
    for (int i = zero_pos; i >= 0; i -= mult)
    {
        ret = min(ret, dp[i]);
    }
    return ret;
}

void solve()
{
    cin >> w >> h;
    cin >> house_x >> house_y;
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    for (auto [a, b] : arr)
    {
        all_dirs.insert(a);
        all_dirs.insert(b);
        all_dirs.insert(-a);
        all_dirs.insert(-b);
    }

    // we only have to consider x and y axes separately, because x wont contribute to reaching y and vice versa.
    // check all 4 directions
    // to reach, (init_x || init_y) + qty * all_dirs[i] % (w || h) == 0;
    // now it boils down to finding minimum elements from all_dirs to reach target sum of a multiple of w or h, from a given starting point

    // How to find min elements to get to multiple? UNBOUNDED KNAPSACK
    // theory: if we iterate through 500 multiples and there's no solution, we know it's impossible?
    // Worst case: O(nk) ~ 20 * maxk = 5000000
    // For 4 directions: 2e7 operations, ez.

    int res = inf;
    // ^ / V
    res = min(res, getBest(house_y, h));
    // < / >
    res = min(res, getBest(house_x, w));
    if (res == inf)
    {
        cout << "No";
        return;
    }
    cout << res;
}

signed main()
{
#ifndef LOCAL
    freopen("pipesin.txt", "r", stdin);
    freopen("pipesout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
