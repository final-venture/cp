class Solution {
private:
    int n;
    vector<vector<int>> dp;

public:
    inline int getVal(int r, int c) {
        if (r < 0 || r >= n || c < 0 || c >= n)
            return 0;
        return dp[r][c];
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        dp.resize(n, vector<int>(n, 0));
        vector<pair<int, int>> dirs1 = {{1, -1}, {1, 0}, {1, 1}};
        vector<pair<int, int>> dirs2 = {{ -1, 1}, {0, 1}, {1, 1}};
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < j && j < n - 1 - i) {
                    fruits[i][j] = 0;
                }
                if (j < i && i < n - 1 - j) {
                    fruits[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            ret += fruits[i][i];
        }
        dp[0][n - 1] = fruits[0][n - 1];
        dp[n - 1][0] = fruits[n - 1][0];
        for (int r = 1; r < n - 1; ++r) {
            for (int c = r + 1; c < n; ++c) {
                for (auto [dr, dc] : dirs1) {
                    int nr = r - dr, nc = c - dc;
                    dp[r][c] = max(dp[r][c], fruits[r][c] + getVal(nr, nc));
                }
            }
        }
        for (int c = 1; c < n - 1; ++c) {
            for (int r = c + 1; r < n; ++r) {
                for (auto [dr, dc] : dirs2) {
                    int nr = r - dr, nc = c - dc;
                    dp[r][c] = max(dp[r][c], fruits[r][c] + getVal(nr, nc));
                }
            }
        }
        ret += dp[n - 1][n - 2];
        ret += dp[n - 2][n - 1];

        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        return ret;
    }
};
