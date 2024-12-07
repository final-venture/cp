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
private:
    int tour_in[100005]; int tour_out[100005];
    vector<int> a { -1};
    int idx = 1;
public:
    void dfs(TreeNode* node, int depth)
    {
        if (!node) return;
        tour_in[node -> val] = idx;
        ++idx;
        a.push_back(depth);
        dfs(node -> left, depth + 1);
        dfs(node -> right, depth + 1);
        tour_out[node -> val] = idx;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        int n = a.size();
        vector<int> pfx(n, 0);
        vector<int> sfx(n + 1, 0);
        for (int i = 1; i < n; ++i)
        {
            pfx[i] = max(pfx[i - 1], a[i]);
        }
        for (int i = n - 1; i >= 1; --i)
        {
            sfx[i] = max(sfx[i + 1], a[i]);
        }
        vector<int> res;
        for (int q : queries)
        {
            int pfx_i = tour_in[q] - 1;
            int sfx_i = tour_out[q];
            int cand = max(pfx[pfx_i], sfx[sfx_i]);
            res.push_back(cand);
        }
        return res;
    }
};
