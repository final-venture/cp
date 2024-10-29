class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int res = 0;

        while (j < n - 1)
        {
            int farthest = 0;
            while (i <= j)
            {
                farthest = max(i + nums[i], farthest);
                ++i;
            }
            i = j + 1;
            j = farthest;
            ++res;
        }
        return res;
    }
};
