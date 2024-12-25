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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return { };
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int currl = 0;
        vector<int> ret;
        int cand = INT_MIN;
        while (!q.empty())
        {
            auto [node, layer] = q.front();
            q.pop();
            if (layer > currl)
            {
                ++currl;
                ret.push_back(cand);
                cand = INT_MIN;
            }
            cand = max(cand, node -> val);
            if (node -> left) q.push({node -> left, layer + 1});
            if (node -> right) q.push({node -> right, layer + 1});
        }
        ret.push_back(cand);
        return ret;
    }
};
