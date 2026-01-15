class Solution
{
public:
    long long maximumScore(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sfxMin(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; --i)
        {
            sfxMin[i] = min(sfxMin[i + 1], nums[i]);
        }
        long long pfx = 0;
        long long ret = INT_MIN;
        for (int i = 0; i < n - 1; ++i)
        {
            pfx += nums[i];
            ret = max(ret, pfx - sfxMin[i + 1]);
        }
        return ret;
    }
};
