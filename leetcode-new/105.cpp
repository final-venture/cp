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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        deque<int> dq(preorder.begin(), preorder.end());
        return dfs(dq, inorder);
    }
    TreeNode *dfs(deque<int> &dq, vector<int> &inorder)
    {
        if (inorder.empty())
            return nullptr;
        int val = dq.front();
        dq.pop_front();
        TreeNode *node = new TreeNode(val);

        auto it = find(inorder.begin(), inorder.end(), val);
        auto idx = it - inorder.begin();

        vector<int> leftio(inorder.begin(), inorder.begin() + idx);
        vector<int> rightio(inorder.begin() + idx + 1, inorder.end());

        node->left = dfs(dq, leftio);
        node->right = dfs(dq, rightio);
        return node;
    }
};
