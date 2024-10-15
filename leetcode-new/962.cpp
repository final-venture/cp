class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        int longest = 0;
        vector<int> stack;
        for (int i = 0; i < n; i++)
        {
            if (stack.empty() || nums[stack.back()] > nums[i])
            {
                stack.push_back(i);
            }
        }
        for (int j = n - 1; j >= 0; j--)
        {
            while (!stack.empty() && nums[stack.back()] <= nums[j])
            {
                longest = max(longest, j - stack.back());
                stack.pop_back();
            }
        }
        return longest;
    }
};