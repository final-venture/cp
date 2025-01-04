#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9
#define int ll

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

const int N = 1e6 + 10;
const int LOG = 22;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // greedy approach to find maxx.
    vector<int> cycSz;
    vector<int> seen(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (seen[i]) continue;
        int curr = i;
        int candSz = 0;
        while (!seen[curr])
        {
            seen[curr] = 1;
            ++candSz;
            curr = a[curr];
            --curr;
            // cout << curr << '\n';
        }
        if (candSz) cycSz.push_back(candSz);
    }
    // for (auto x : cycSz) cout << x << ' ';
    // for (int sz : cycSz) cout << sz << ' ';
    int currk = k;
    int maxx = 0;
    for (auto sz : cycSz) // greedily do all affect-2's
    {
        if (currk >= sz / 2)
        {
            currk -= sz / 2;
            maxx += (sz / 2) * 2;
        }
        else
        {
            maxx += 2 * currk;
            currk = 0;
            break;
        }
    }
    maxx += min(currk, n - maxx); // affect-2 removals/ungifts have all been used, so we just add 1 * currk (n - maxx is max we can affect still)

    // dp (knapsack) to find minn. We can never make less than k balls get no gifts
    // That means if we should try to make perfect cycles. If we can't, return k + 1
    // Because if we pick optimally (try to get minn) from an incomplete cycle, 1 more element will be affected
    vector<int> szCnt(n + 1, 0);
    for (auto sz : cycSz)
    {
        ++szCnt[sz];
    }

    // for (int i = 0; i <= n; ++i)
    // {
    //     cout << szCnt[i] << ' ';
    // }

    bitset < N + 1 > dp; // use the const int, otherwise error.
    dp.set(0);

    for (int i = 1; i <= n; ++i)
    {
        if (!szCnt[i]) continue;
        int cand = szCnt[i];
        int po2 = 1;
        while (cand)
        {
            int subby = min(cand, po2);
            cand -= subby;
            dp |= dp << (subby * i);
            po2 <<= 1;
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << dp[i] << ' ';
    // }
    if (dp[k])
    {
        cout << k << ' ' << maxx;
    }
    else
    {
        cout << k + 1 << ' ' << maxx;
    }
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
