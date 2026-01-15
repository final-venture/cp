class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ret(2 * n);
        for (int i = 0; i < 2 * n; ++i)
        {
            ret[i] = nums[i % n];
        }
        return ret;
    }
};
