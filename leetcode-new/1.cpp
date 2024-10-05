class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> hashMap;

        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (hashMap.count(complement))
            {
                return {hashMap[complement], i};
            }
            hashMap[nums[i]] = i;
        }
        return {};
    }
};
