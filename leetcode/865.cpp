class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, int> depths;

        auto getDepth = [&](TreeNode * node, auto & func)
        {
            if (!node) return 0;
            if (depths.find(node) == depths.end())
            {
                depths[node] = max(func(node -> left, func), func(node -> right, func)) + 1;
            }
            return depths[node];
        };

        TreeNode* ret = root;

        while (true)
        {
            int leftDepth = getDepth(ret -> left, getDepth);
            int rightDepth = getDepth(ret -> right, getDepth);

            if (leftDepth == rightDepth) break;
            ret = (leftDepth > rightDepth) ? ret -> left : ret -> right;
        }

        return ret;
    }
};
