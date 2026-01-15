class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ret(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            ret[i] = ret[i - 1] + nums[i - 1];
        }
        ret.erase(ret.begin());
        return ret;
    }
};
