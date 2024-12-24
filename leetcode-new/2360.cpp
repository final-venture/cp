class Solution {
private:
    vector<int> in_st;
    vector<int> st;
    vector<int> edges;
    vector<int> seen;
    int ret = -1;
public:
    void dfs(int node)
    {
        in_st[node] = 1;
        st.push_back(node);
        int nei = edges[node];
        if (nei == -1 || seen[nei]) return;
        if (in_st[nei])
        {
            int cand = 0;
            while (!st.empty())
            {
                int x = st.back();
                st.pop_back();
                ++cand;
                // cout << x << '\n';
                seen[x] = 1;
                in_st[x] = 0;
                if (x == nei && cand) ret = max(ret, cand);
            }
            // return;
        }
        else
        {
            if (!seen[nei]) dfs(nei);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        in_st.resize(n, 0); seen.resize(n, 0);
        this -> edges = edges;
        for (int i = 0; i < n; ++i)
        {
            if (!seen[i]) {
                // in_st.resize(n, 0);
                st.clear();
                // cout << i << '\n';
                dfs(i);
            }
        }
        return ret;
    }
};
