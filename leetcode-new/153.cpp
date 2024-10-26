class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r - 1)
        {
            int m = (l + r) >> 1;
            if (nums[m] < nums[l])
                r = m;
            else
                l = m;
        }
        return min(nums[0], nums[r]);
    }
};
