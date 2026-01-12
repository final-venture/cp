class Solution
{
public:
    int centeredSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int ret = 0;
        for (int st = 0; st < n; ++st)
        {
            unordered_set<int> currSet;
            int currSum = 0;
            for (int i = st; i < n; ++i)
            {
                currSum += nums[i];
                currSet.insert(nums[i]);
                if (currSet.contains(currSum))
                {
                    ++ret;
                }
            }
        }
        return ret;
    }
};
