class TreeAncestor {
    vector<vector<int>> up;
    const int LOG = 16;
// up[i][j] == 2^j-th ancestor of i
public:
    TreeAncestor(int n, vector<int>& parent) {
        up = vector<vector<int>>(n, vector<int>(LOG, -1));
        for (int i = 0; i < n; ++i)
        {
            up[i][0] = parent[i];
        }
        for (int j = 1; j < LOG; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                if (up[i][j - 1] != -1)
                {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
                else
                {
                    up[i][j] = -1;
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = LOG - 1; i >= 0; --i)
        {
            if (k & (1 << i))
            {
                node = up[node][i];
            }
            if (node == -1) return node;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */