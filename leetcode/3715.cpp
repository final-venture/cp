class Solution {
private:
    vector<vector<int>> adj;
    vector<int> nums;
    int core[100005];
    int core_cnt[100005];
    long long dfs(int node, int par) {
        int val = nums[node];
        // count how much to add to ret
        long long ret = core_cnt[core[val]];
        // add required numbers for children
        core_cnt[core[val]]++;
        for (int nei : adj[node]) {
            if (nei == par) {
                continue;
            }
            ret += dfs(nei, node);
        }
        // remove required numbers for children
        core_cnt[core[val]]--;
        return ret;
    }
    void generateCores(int n) {
        iota(core, core + (n + 3), 0);
        for (int i = 2; i * i <= n + 2; ++i) {
            int square = i * i;
            for (int j = square; j <= n + 2; j += square) {
                while (core[j] % square == 0) {
                    core[j] /= square;
                }
            }
        }
    }
public:
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        // there are sqrt(n) perfect numbers
        // looks like an nsqrt(n) sol
        // nvm
        int maxx = *max_element(nums.begin(), nums.end());
        adj.resize(n); this->nums = nums;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i < maxx + 4; ++i) {
            core_cnt[i] = 0;
        }
        generateCores(maxx + 1);
        return dfs(0, -1);
    }
};
