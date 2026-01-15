/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    int timer = 0;
    const int MOD = 1e9 + 7;
    int dp[100000];
    int dfs(TreeNode *node, int time)
    {
        if (!node)
        {
            return 0;
        }
        int left = dfs(node->left, ++timer);
        int right = dfs(node->right, ++timer);
        return dp[time] = node->val + left + right;
    }

public:
    int maxProduct(TreeNode *root)
    {
        long long ret = 0;
        dfs(root, timer);
        for (int i = 1; i < 60000; ++i)
        {
            ret = max(ret, 1LL * (dp[0] - dp[i]) * dp[i]);
        }
        return ret % MOD;
    }
};
