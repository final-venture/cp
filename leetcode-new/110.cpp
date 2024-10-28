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
public:
    bool res = true;
    bool isBalanced(TreeNode *root)
    {
        helper(root);
        return res;
    }
    int helper(TreeNode *&node)
    {
        if (!node || !res)
            return 0;
        int left = helper(node->left);
        int right = helper(node->right);
        if (abs(left - right) > 1)
        {
            res = false;
        }
        return 1 + max(left, right);
    }
};
