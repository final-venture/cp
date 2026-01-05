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
    int maxLevelSum(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        vector<int> summ{INT_MIN};
        int currLayer = 0;
        q.push({root, 1});
        while (!q.empty())
        {
            auto &[node, layer] = q.front();
            if (layer > currLayer)
            {
                currLayer = layer;
                summ.push_back(0);
            }
            summ.back() += node->val;
            if (node->left)
                q.push({node->left, layer + 1});
            if (node->right)
                q.push({node->right, layer + 1});
            q.pop();
        }
        return max_element(summ.begin(), summ.end()) - summ.begin();
    }
};
