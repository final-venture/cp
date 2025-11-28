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

int brute(int n, int t, vector<int>& rawnums)
{
    vector<int> nums(n * t);
    for (int i = 0; i < n; ++i)
    {
        nums[i] = rawnums[i];
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
    return *max_element(dp.begin(), dp.end());
}

int solve(int n, int t, vector<int>& rawnums)
{
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
        nums[i] = rawnums[i];
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
    return max(preRes + remRpt * cntMax, preRes + remRpt * maxCnt);
}

int main()
{
    init();
    srand(static_cast<unsigned int>(time(NULL)));
    int cnt = 1;
    while (cnt++ <= 1000)
    {
        int n = rand() % 3 + 1;
        int t = rand() % 200 + 1;
        vector<int> rawnums;
        rawnums = vector<int>(n);
        for (int i = 0; i < n; ++i)
        {
            rawnums[i] = rand() % 10 + 1;
        }
        int x = solve(n, t, rawnums);
        int y = brute(n, t, rawnums);
        if (x != y)
        {
            cout << x << ' ' << y << '\n';
            cout << n << ' ' << t << '\n';
            for (int x : rawnums) cout << x << ' ';
            break;
        }
    }
    return 0;
}
