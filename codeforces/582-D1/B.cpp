#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    int n, t;
    cin >> n >> t;
    int remRpt = 0;
    if (t > 100)
    {
        remRpt = t - 100;
        t = 100;
    }
    vector<int> nums(t * n);
    unordered_map<int, int> n2c;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; ++i)
    {
        n2c[nums[i]]++;
    }
    int maxNum = *max_element(nums.begin(), nums.end());
    int cntMax = n2c[maxNum];
    int maxCnt = 0;
    for (auto& [n, c] : n2c)
    {
        maxCnt = max(maxCnt, c);
    }
    for (int i = n; i < t * n; ++i)
    {
        nums[i] = nums[i - n];
    }
    vector<int> dp(t * n, 1);
    for (int i = t * n - 2; i >= 0; --i)
    {
        for (int j = i + 1; j < t * n; ++j)
        {
            if (nums[i] <= nums[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    int preRes = *max_element(dp.begin(), dp.end());
    cout << max(preRes + remRpt * cntMax, preRes + remRpt * maxCnt) << '\n';
}

int main()
{
    init();
    solve();
    return 0;
}
