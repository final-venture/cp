class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int longest = 0;
        set<int> numSet(nums.begin(), nums.end());
        for (int num : nums)
        {
            int curr = 0;
            if (numSet.find(num + 1) == numSet.end())
            {
                while (numSet.find(num--) != numSet.end())
                {
                    curr++;
                }
                longest = max(longest, curr);
            }
        }
        return longest;
    }
};
