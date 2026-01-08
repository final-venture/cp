class Solution
{
public:
    vector<int> maxValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pfx(n + 1, 0);
        vector<int> sfx(n + 1, INT_MAX);
        for (int i = 1; i <= n; ++i)
        {
            pfx[i] = max(pfx[i - 1], nums[i - 1]);
        }
        for (int i = n - 1; i >= 0; --i)
        {
            sfx[i] = min(sfx[i + 1], nums[i]);
        }
        vector<int> ret(n);
        ret[n - 1] = pfx[n];
        for (int i = n - 2; i >= 0; --i)
        {
            if (sfx[i + 1] < pfx[i + 1])
            {
                ret[i] = ret[i + 1];
            }
            else
            {
                ret[i] = pfx[i + 1];
            }
        }
        return ret;
    }
};
