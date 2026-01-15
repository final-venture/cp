class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ret = 0, n = nums.size();
        int curr = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 1)
            {
                ++curr;
            }
            else
            {
                curr = 0;
            }
            ret = max(ret, curr);
        }
        return ret;
    }
};
