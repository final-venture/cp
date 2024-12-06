class TreeAncestor {
private:
    int LOG;
    vector<vector<int>> jump;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while ((n >> LOG) > 0)
        {
            ++LOG;
        }
        jump = vector<vector<int>>(n, vector<int>(LOG));
        // jump[i][j] refers to 2^j'th parent of node i
        for (int i = 0; i < n; ++i)
        {
            jump[i][0] = parent[i];
        }

        for (int j = 1; j < LOG; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                if (jump[i][j - 1] == -1)
                    jump[i][j] = -1;
                else
                    jump[i][j] = jump[jump[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < LOG; ++i)
        {
            if (node == -1)
                return -1;
            if ((1 << i) & k)
            {
                node = jump[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */