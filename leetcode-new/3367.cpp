// Approach: when we dfs to a node, we only consider everything below it - forget about the parent node in the dfs.
// Simply consider two cases:
// Case 1: Include max of K parent -> children edges
// Case 2: Include max of K - 1 parent -> children edges
// This is where postprocessing comes in
// Once we return to the parent of the parent (grandparent), we now have the 2 cases for each child node of this parent node. Now if we include an edge connecting grandparent -> a parent, we must remove a worse parent -> child edge on the parent node. This will be implicitly done using a sorted benefit array.
#define ll long long
class Solution {
private:
    int k;
    vector<vector<pair<int, int>>> adj;
    vector<vector<ll>> dp;
public:
    void dfs(int node, int par)
    {
        ll wtSum = 0;
        vector<int> diffs;
        // net gains for not including each particular edge in nei - including K-1 edges & neiWt compared to K edges & not neiWt
        for (auto& [neiNode, neiWt] : adj[node])
        {
            if (neiNode == par) continue;
            dfs(neiNode, node);
            // this part will implicitly take into account case 1 in the dp
            // (no parent edge) to be considered for the edges one layer below it - see further code
            diffs.push_back((neiWt + dp[neiNode][1]) - dp[neiNode][0]);
            // first accumulate base case - i.e. what is the combined sum when we include a max of k edges for each neiNode
            wtSum += dp[neiNode][0];
        }
        sort(diffs.begin(), diffs.end(), greater<>());
        int nn = diffs.size();

        dp[node][0] = wtSum;
        for (int i = 0; i < min(k, nn); ++i)
        {
            if (diffs[i] > 0)
            {
                dp[node][0] += diffs[i];
            }
        }

        dp[node][1] = wtSum;
        // iterate through a max of k - 1 edges (implicitly) through the diffs/benefits array in descending order
        for (int i = 0; i < min(k - 1, nn); ++i)
        {
            // if there is a benefit to (including this edge && excluding a worse edge on the child)
            if (diffs[i] > 0)
            {
                // add the benefit
                dp[node][1] += diffs[i];
            }
        }
    }

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        this -> k = k;
        int n = edges.size();
        adj.resize(n + 2);
        dp.resize(n + 2, vector<ll>(2, 0));
        for (auto& edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        dfs(0, -1);
        // return dp[0][0] because we should always include a max of k edges rather than k - 1 edges - since node 0 has no parent.
        return dp[0][0];
    }
};
