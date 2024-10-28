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
    int res = INT_MIN;

public:
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return res;
    }
    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;
        int maxleft = max(0, dfs(node->left));
        int maxright = max(0, dfs(node->right));
        res = max(res, maxleft + maxright + node->val);
        return node->val + max(maxleft, maxright);
    }
};
