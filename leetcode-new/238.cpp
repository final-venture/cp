class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pfx(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            pfx[i] = pfx[i] * pfx[i - 1];
        }
        vector<int> sfx(nums.begin(), nums.end());
        for (int i = n - 2; i >= 0; i--)
        {
            sfx[i] = sfx[i] * sfx[i + 1];
        }
        nums[0] = sfx[1];
        nums[n - 1] = pfx[n - 2];
        for (int i = 1; i < n - 1; i++)
        {
            nums[i] = pfx[i - 1] * sfx[i + 1];
        }
        return nums;
    }
};
