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
    int minimumOperations(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int curr = 0;
        int ret = 0;
        vector<int> cand;
        vector<int> scand;
        unordered_map<int, int> n2i;
        while (!q.empty())
        {
            auto [node, layer] = q.front();
            q.pop();
            if (layer > curr)
            {
                int cnt = 0;
                int n = cand.size();
                vector<int> scand(n);
                for (int i = 0; i < n; ++i)
                {
                    scand[i] = cand[i];
                    n2i[cand[i]] = i;
                }
                sort(scand.begin(), scand.end());
                // for (int x : cand) cout << x << ' ';
                // cout << '\n';
                // for (int x : scand) cout << x << ' ';
                // cout << '\n';
                for (int i = 0; i < n; ++i)
                {
                    if (scand[i] != cand[i])
                    {
                        int tmpIdx = n2i[scand[i]];
                        swap(cand[i], cand[tmpIdx]);
                        n2i[cand[tmpIdx]] = tmpIdx;
                        n2i[cand[i]] = i;
                        ++cnt;
                    }
                }
                ret += cnt;
                // cout << cnt << '\n';
                cand.clear();
                n2i.clear();
                ++curr;
            }
            if (!node) continue;
            cand.push_back(node -> val);
            q.push({node -> left, layer + 1}); q.push({node -> right, layer + 1});
        }
        return ret;
    }
};
