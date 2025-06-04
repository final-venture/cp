class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        helper(res, n, 0, 0, "");
        return res;
    }
    void helper(auto &res, int n, int o, int c, string cand)
    {
        if (cand.length() == n * 2)
        {
            res.push_back(cand);
        }
        if (o < n)
        {
            helper(res, n, o + 1, c, cand + "(");
        }
        if (c < o)
        {
            helper(res, n, o, c + 1, cand + ")");
        }
    }
};
