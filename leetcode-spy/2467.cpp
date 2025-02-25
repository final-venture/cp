class Solution 
{
private:
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> n2i;
    vector<int> amount;
    int k;

    int dfs(int node, int par) 
    {
        int ret;
        if (n2i[node] != -1) 
        {
            int i = n2i[node];
            if (2 * i < k) ret = amount[node];
            else if (2 * i > k) ret = 0;
            else ret = amount[node] / 2;
        } 
        else 
        {
            ret = amount[node];
        }

        int maxx = INT_MIN;
        for (int child : adj[node]) 
        {
            if (child != par) 
            {
                int summ = dfs(child, node);
                if (summ > maxx) maxx = summ;
            }
        }

        if (maxx != INT_MIN) ret += maxx;
        return ret;
    }

    void dfs_parent(int node, int par) 
    {
        parent[node] = par;
        for (int child : adj[node]) 
        {
            if (child != par) 
            {
                dfs_parent(child, node);
            }
        }
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
    {
        int n = amount.size();
        
        adj.resize(n);
        parent.resize(n, -1);
        n2i.resize(n, -1);
        this -> amount = amount;

        for (auto& edge : edges) 
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs_parent(0, -1);

        vector<int> path;
        int current = bob;
        while (current != -1) 
        {
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(), path.end());
        
        k = path.size() - 1;

        for (int i = 0; i <= k; ++i) 
        {
            n2i[path[i]] = i;
        }

        return dfs(0, -1);
    }
};
