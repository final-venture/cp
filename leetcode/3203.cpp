class Solution {
public:
    vector<int> getMaxD(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v); adj[v].push_back(u);
        }

        vector<int> in(n + 1);
        calcDown(0, -1, adj, in);

        vector<int> out(n + 1);
        out[0] = 0;
        calcUp(0, -1, adj, in, out);

        for (int i = 0; i < n + 1; ++i)
        {
            out[i] = max(out[i] + 1, in[i]);
        }
        return out;
    }

    int calcDown(int node, int par, vector<vector<int>>& adj, vector<int>& dp)
    {
        int ret = 1;
        int add = 0;
        for (int nei : adj[node])
        {
            if (nei != par)
                add = max(add, calcDown(nei, node, adj, dp));
        }
        ret += add;
        return dp[node] = ret;
    }

    void calcUp(int node, int par, vector<vector<int>>& adj, vector<int>& dpin, vector<int>& dpout)
    {
        int maxx1 = INT_MIN, maxx2 = INT_MIN;
        for (int nei : adj[node])
        {
            if (nei == par) continue;
            if (dpin[nei] > maxx1)
            {
                maxx2 = maxx1;
                maxx1 = dpin[nei];
            }
            else if (dpin[nei] > maxx2)
            {
                maxx2 = dpin[nei];
            }
        }

        for (int nei : adj[node])
        {
            if (nei == par) continue;
            int maxx = (maxx1 == dpin[nei]) ? maxx2 : maxx1;
            dpout[nei] = max(dpout[node] + 1, maxx + 1);
            calcUp(nei, node, adj, dpin, dpout);
        }
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> dep1 = getMaxD(edges1);
        vector<int> dep2 = getMaxD(edges2);

        int dia1 = 0, dia2 = 0;
        int min_dep1 = INT_MAX, min_dep2 = INT_MAX;
        for (auto d : dep1)
        {
            dia1 = max(d, dia1);
            min_dep1 = min(min_dep1, d);
        }
        for (auto d : dep2)
        {
            dia2 = max(d, dia2);
            min_dep2 = min(min_dep2, d);
        }

        int ret = max({dia1, dia2, min_dep1 + min_dep2});
        return ret - 1;
    }
};
