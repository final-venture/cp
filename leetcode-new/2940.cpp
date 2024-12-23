class Solution {
private:
    static constexpr int LOG = 16;
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        const int n = heights.size();
        const int nn = queries.size();

        int up[LOG][n]; // up[i][j] is 2^i-th ancestor of node j.
        memset(up, -1, sizeof(up));
        // vector<int> depths(n, 1); // depth = 0 houses the node -1.

        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && heights[st.top()] < heights[i])
            {
                // depths[st.back()] = depths[i] + 1;
                up[0][st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for (int i = 1; i < LOG; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (up[i - 1][j] == -1) continue;
                up[i][j] = up[i - 1][up[i - 1][j]];
            }
        }

        // for (int x : up[0]) cout << x << ' ';
        // cout << '\n';
        // for (int x : depths) cout << x << ' ';

        vector<int> ret(nn);
        for (int i = 0; i < nn; ++i)
        {
            int a = queries[i][0], b = queries[i][1];
            if (b < a) // b always has greater idx
            {
                swap(a, b);
            }
            // int d = depths[a] - depths[b];
            // cout << d << '\n';
            // for (int i = LOG - 1; i >= 0; --i)
            // {
            //     if ((1 << i) & d)
            //     {
            //         // -1 error OOB shouldn't occur
            //         a = up[i][a];
            //     }
            // }
            if (a == b)
            {
                ret[i] = a;
                continue;
            }
            if (heights[a] < heights[b])
            {
                ret[i] = b;
                continue;
            }
            if (heights[a] == heights[b])
            {
                ret[i] = up[0][b];
                continue;
            }
            for (int i = LOG - 1; i >= 0; --i)
            {
                if (up[i][b] != -1 && heights[up[i][b]] <= heights[a])
                {
                    b = up[i][b];
                }
            }
            ret[i] = up[0][b];
        }
        return ret;
    }
};
