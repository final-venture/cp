// O(n^2), O(n^2)
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

// O(n), O(n)
class Solution
{
private:
    unordered_map<int, int> n2i;
    int poi = 0;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            n2i[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
    TreeNode *build(vector<int> &preorder, int l, int r)
    {
        if (l > r)
            return nullptr;
        int nodeval = preorder[poi++];
        int ioi = n2i[nodeval];
        TreeNode *node = new TreeNode(nodeval);
        node->left = build(preorder, l, ioi - 1);
        node->right = build(preorder, ioi + 1, r);
        return node;
    }
};
