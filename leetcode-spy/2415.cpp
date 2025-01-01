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
class Solution {
public:
    void dfs(TreeNode* lnode, TreeNode* rnode, int parity)
    {
        if (lnode == nullptr || rnode == nullptr) return;
        if (parity)
        {
            int tmp = lnode -> val;
            lnode -> val = rnode -> val;
            rnode -> val = tmp;
        }
        dfs(lnode -> left, rnode -> right, !parity);
        dfs(lnode -> right, rnode -> left, !parity);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root -> left, root -> right, 1);
        return root;
    }
};
