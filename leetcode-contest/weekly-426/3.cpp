class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
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

        unordered_set<int> seen;

        vector<int> shortest1(n + 1);
        for (int i = 0; i <= n; ++i) {
            seen.clear();
            queue<pair<int, int>> q;
            q.push({i, 0});
            int res = 0;
            while (!q.empty()) {
                auto [node, dist] = q.front();
                // cout << node << ' ' << dist << '\n';
                q.pop();
                seen.insert(node);
                if (dist <= k) {
                    ++res;
                }
                if (k > 0 && dist < k) {
                    for (int neiNode : adj1[node]) {
                        if (seen.find(neiNode) == seen.end()) {
                            q.push({neiNode, dist + 1});
                        }
                    }
                }
            }
            shortest1[i] = res;
        }

        vector<int> shortest2(m + 1);
        for (int i = 0; i <= m; ++i) {
            seen.clear();
            queue<pair<int, int>> q;
            q.push({i, 0});
            int res = 0;
            while (!q.empty()) {
                auto [node, dist] = q.front();
                q.pop();
                seen.insert(node);
                if (dist <= k - 1) {
                    ++res;
                }
                if (k > 0 && dist < k - 1) {
                    for (int neiNode : adj2[node]) {
                        if (seen.find(neiNode) == seen.end()) {
                            q.push({neiNode, dist + 1});
                        }
                    }
                }
            }
            shortest2[i] = res;
        }
        // for (auto& x : shortest1)
        //     cout << x << ' ';
        // cout << '\n';
        // for (int i = 2000; i < m + 2005; ++i)
        //     cout << shortest2[i] << ' ';
        int xdd = *max_element(shortest2.begin(), shortest2.end());
        vector<int> resvec(shortest1.begin(), shortest1.end());
        for (int i = 0; i < n + 1; ++i) {
            resvec[i] += xdd;
        }
        return resvec;
    }
};
