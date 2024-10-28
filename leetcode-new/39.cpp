class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> cand;
        vector<vector<int>> res;
        dfs(0, 0, cand, res, candidates, target);
        return res;
    }

    void dfs(int sum, int i, vector<int> &cand, vector<vector<int>> &res, vector<int> &candidates, int target)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(cand);
            return;
        }
        if (i >= candidates.size())
            return;
        cand.push_back(candidates[i]);
        dfs(sum + candidates[i], i, cand, res, candidates, target);
        cand.pop_back();
        dfs(sum, i + 1, cand, res, candidates, target);
    }
};
