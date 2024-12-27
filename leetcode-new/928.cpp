class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> seen;
        function<int(int, int)> dfs = [&] (int node, int ignore)
        {
            if (seen[node] || node == ignore) return 0;
            // cout << node << ' ' << ignore << '\n';
            seen[node] = 1;
            int res = 1;
            for (int nei = 0; nei < n; ++nei)
            {
                if (!graph[node][nei]) continue;
                res += dfs(nei, ignore);
            }
            return res;
        };

        pair<int, int> minf_midx {333, 333};
        for (auto ignore : initial)
        {
            int infected = 0;
            seen.assign(n, 0);
            for (auto node : initial)
            {
                // for (int x : seen) cout << x << ' ';
                // cout << '\n';
                int add = dfs(node, ignore);
                // cout << "add " << add << ' ';
                // cout << '\n';
                infected += add;
            }
            // cout << infected << '\n';
            if (infected < minf_midx.first)
            {
                // cout << "hello" << '\n';
                minf_midx.first = infected;
                minf_midx.second = ignore;
            }
            else if (infected == minf_midx.first)
            {
                minf_midx.second = min(minf_midx.second, ignore);
            }
        }
        return minf_midx.second;
    }
};
