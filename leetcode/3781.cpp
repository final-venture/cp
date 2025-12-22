class Solution
{
public:
    long long maximumScore(vector<int> &nums, string s)
    {
        int n = nums.size();
        long long ret = 0;
        multiset<int, greater<>> numSet;
        for (int i = 0; i < n; ++i)
        {
            numSet.insert(nums[i]);
            if (s[i] == '1')
            {
                auto it = numSet.begin();
                ret += (*it);
                numSet.erase(it);
            }
        }
        return ret;
    }
};
