class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> ret(n, false);
        int curr_num = 0;
        for (int i = 0; i < n; ++i)
        {
            curr_num = curr_num * 2 + nums[i];
            curr_num %= 5;
            if (curr_num == 0)
            {
                ret[i] = true;
            }
        }
        return ret;
    }
};
