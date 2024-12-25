// Tree Pruning
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        vector<int> deg(n);
        for (auto& edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v); adj[v].push_back(u);
        }

        // we want to get rid of all leaf nodes, so they can step infinitely
        vector<int> steps(n, 30005);
        for (int i = 0; i < n; ++i)
        {
            if (coins[i]) steps[i] = 2;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            deg[i] = adj[i].size();
            // we want to go from bottom up (leaves first), so:
            if (deg[i] == 1) q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (!steps[node]) continue;
            --n;
            for (int nei : adj[node])
            {
                steps[nei] = min(steps[nei], steps[node] - 1);
                --deg[nei];
                if (deg[nei] == 1) q.push(nei);
            }
        }
        return 2 * max(0, n - 1);
    }
};


// In-Out Tree DP - Educational, less efficient approach:
// https://www.youtube.com/watch?v=wUmuRsTGQxs
// Credit: codingMohan

const int N = 3e4 + 1;

vector<int> has_coin;
vector<vector<int>> g(N);
vector<vector<int>> cnt_coins_subtree (N, vector<int>(4, 0));
vector<int> min_time_for_subtree (N);
vector<vector<int>> cnt_coins_root (N, vector<int>(4, 0));
vector<int> min_time_for_root (N);

class Solution {
    void MergeCoins (vector<int>& target, const vector<int>& src) {
        target[1] += src[0];
        target[2] += src[1];
        target[3] += src[2] + src[3];
    }

    void RemoveCoins (vector<int>& target, const vector<int>& src) {
        target[1] -= src[0];
        target[2] -= src[1];
        target[3] -= (src[2] + src[3]);
    }

    void MergeMinTime (int& target_min_time, const vector<int>& src_coins, const int src_min_time) {
        if ((src_coins[2] + src_coins[3]) > 0)
            target_min_time += 2 + src_min_time;
    }

    void RemoveMinTime (int& target_min_time, const vector<int>& src_coins, const int src_min_time) {
        if ((src_coins[2] + src_coins[3]) > 0)
            target_min_time -= (2 + src_min_time);
    }

    void dfs_in (int src, int par) {
        for (auto child : g[src]) {
            if (child == par) continue;
            dfs_in (child, src);

            MergeCoins (cnt_coins_subtree[src], cnt_coins_subtree[child]);
            MergeMinTime (min_time_for_subtree[src], cnt_coins_subtree[child], min_time_for_subtree[child]);
        }

        if (has_coin[src]) cnt_coins_subtree[src][0] = 1;
    }

    void dfs_out (int root, int parent) {

        for (auto child : g[root]) {
            if (child == parent) continue;

            vector<int> cnt_coins_except_child = cnt_coins_root[root];
            RemoveCoins (cnt_coins_except_child, cnt_coins_subtree[child]);

            int min_time_except_child = min_time_for_root[root];
            RemoveMinTime (min_time_except_child, cnt_coins_subtree[child], min_time_for_subtree[child]);

            // Calculate the value when "child" becomes 'root'
            cnt_coins_root[child] = cnt_coins_subtree[child];
            MergeCoins (cnt_coins_root[child], cnt_coins_except_child);

            min_time_for_root[child] = min_time_for_subtree[child];
            MergeMinTime (min_time_for_root[child], cnt_coins_except_child, min_time_except_child);


            dfs_out (child, root);
        }
    }

public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();

        has_coin = coins;
        for (int j = 0; j <= n; j ++) {
            g[j].clear();
            min_time_for_subtree[j] = 0;
            min_time_for_root[j] = 0;
            for (int k = 0; k < 4; k ++) {
                cnt_coins_subtree[j][k] = 0;
                cnt_coins_root[j][k] = 0;
            }
        }

        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs_in(0, -1);

        cnt_coins_root[0] = cnt_coins_subtree[0];
        min_time_for_root[0] = min_time_for_subtree[0];
        dfs_out(0, -1);

        int result = 1e9;
        for (int j = 0; j < n; j ++) result = min(result, min_time_for_root[j]);
        return result;
    }
};
