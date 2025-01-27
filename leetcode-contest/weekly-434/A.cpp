class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pfx(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            pfx[i] = pfx[i - 1] + nums[i - 1];
        }
        // for (auto x : pfx) cout << x << ' ';
        int ret = 0;
        for (int i = 1; i < n; ++i)
        {
            int cand = abs(pfx[i] - (pfx[n] - pfx[i]));
            if (cand & 1)
                continue;
            ++ret;
        }
        return ret;
    }
};
©leetcode