class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> seen(1e5 + 5, 0);
        int okCnt = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (seen[nums[i]])
            {
                break;
            }
            seen[nums[i]] = 1;
            ++okCnt;
        }
        int toRemove = n - okCnt;
        if (toRemove % 3 == 0)
        {
            return toRemove / 3;
        }
        else
        {
            return toRemove / 3 + 1;
        }
    }
};
