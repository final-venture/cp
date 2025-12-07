class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        int max_b = 0;
        for (int diff = -50; diff <= 50; ++diff)
        {
            int benny = 0;
            for (int i = 0; i < n; ++i)
            {
                if (nums[i] == k)
                {
                    if (benny > 0)
                        --benny;
                }
                else if (nums[i] + diff == k)
                {
                    ++benny;
                }
                max_b = max(max_b, benny);
            }
        }
        int cnt = count(nums.begin(), nums.end(), k);
        return cnt + max_b;
    }
};
