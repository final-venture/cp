class Solution
{
public:
    int absDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int ret = accumulate(nums.begin(), nums.begin() + k, 0);
        sort(nums.begin(), nums.end(), greater<>());
        for (int i = 0; i < k; ++i)
        {
            ret -= nums[i];
        }
        return abs(ret);
    }
};
