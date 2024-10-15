class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> cand;
        backtrack(nums, 0, res, cand);
        return res;
    }
    void backtrack(vector<int> &nums, int i, vector<vector<int>> &res, vector<int> &cand)
    {
        if (i == nums.size())
        {
            res.push_back(cand);
            return;
        }
        cand.push_back(nums[i]);
        backtrack(nums, i + 1, res, cand);
        cand.pop_back();
        backtrack(nums, i + 1, res, cand);
    }
};
