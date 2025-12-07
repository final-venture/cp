class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();
        unordered_map<int, vector<int>> adj1;
        unordered_map<int, vector<int>> adj2;
        for (auto& x : edges1) {
            int u = x[0];
            int v = x[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for (auto& x : edges2) {
            int u = x[0];
            int v = x[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<int> par1(n + 1);
        vector<int> parcnt1(2, 0);
        unordered_set<int> seen;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            seen.insert(node);
            par1[node] = dist;
            ++parcnt1[dist];
            for (int neiNode : adj1[node]) {
                if (seen.find(neiNode) == seen.end()) {
                    q.push({neiNode, !dist});
                }
            }
        }

        vector<int> parcnt2(2, 0);
        q.push({0, 0});
        seen.clear();
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            seen.insert(node);
            ++parcnt2[dist];
            for (int neiNode : adj2[node]) {
                if (seen.find(neiNode) == seen.end()) {
                    q.push({neiNode, !dist});
                }
            }
        }

        vector<int> resvec(n + 1);
        int req = 0;
        if (parcnt2[1] > parcnt2[0]) req = 1;
        for (int i = 0; i < n + 1; ++i) {
            resvec[i] = parcnt1[par1[i]] + parcnt2[req];
        }
        return resvec;
    }
};
