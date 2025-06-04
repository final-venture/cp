class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int r = n - 1;
        int l = 0;
        while (l < r)
        {
            int m = (l + r) >> 1;
            int count = 0;
            for (int i = 0; i < n; i++)
                if (nums[i] <= m)
                    ++count;
            if (count > m)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
