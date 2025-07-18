#define ll long long
class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 3;
        priority_queue<ll> pqmin;
        priority_queue<ll, vector<ll>, greater<>> pqmax;
        vector<ll> dpmax(3 * n, 0), dpmin(3 * n, 0);
        // dp[i] is for min / max sum before / after i'th index
        // remember EXCLUDE i

        ll rtmin = 0, rtmax = 0; // running total min and max
        for (int i = 0; i < 3 * n; ++i)
        {
            if (pqmin.size() >= n)
            {
                dpmin[i] = rtmin;
            }
            pqmin.push(nums[i]);
            rtmin += nums[i];
            if (pqmin.size() > n)
            {
                ll x = pqmin.top(); // largest element
                pqmin.pop();
                rtmin -= x;
            }
        }

        for (int i = 3 * n - 1; i >= 0; --i)
        {
            pqmax.push(nums[i]);
            rtmax += nums[i];
            if (pqmax.size() > n)
            {
                ll x = pqmax.top(); // smallest element
                pqmax.pop();
                rtmax -= x;
            }
            if (pqmax.size() >= n)
            {
                dpmax[i] = rtmax;
            }
        }

        // for (int x : dpmin)
        // {
        //     cout  << x << ' ';
        // }
        // cout << '\n';
        // for (int x : dpmax)
        // {
        //     cout << x << ' ';
        // }
        // cout << '\n';

        ll ret = LLONG_MAX;
        for (int i = n; i <= 2 * n; ++i)
        {
            // cout << dpmin[i] << ' ' << dpmax[i] << '\n';
            ret = min(ret, dpmin[i] - dpmax[i]);
        }
        return ret;
    }
};
