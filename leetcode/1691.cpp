class Solution {
private:
    const int MAXN = 102;
    const int MAXW = 102, MAXL = 102, MAXH = 102;
    int dp[102];

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // dp[i][j][k] is the max height up to i when the base is j * k.
        int n = cuboids.size();
        dp[0] = 0;
        for (int i = 0; i < n; ++i) { sort(cuboids[i].begin(), cuboids[i].end(), greater<>()); }

        sort(cuboids.begin(), cuboids.end(), greater<>());

        for (int i = 1; i <= n; ++i) {
            int H = cuboids[i - 1][0], W = cuboids[i - 1][1], L = cuboids[i - 1][2];
            for (int j = 0; j < i; ++j) {
                int prevH = 105, prevW = 105, prevL = 105;
                if (j > 0) {
                    prevH = cuboids[j - 1][0];
                    prevW = cuboids[j - 1][1];
                    prevL = cuboids[j - 1][2];
                }
                if (H <= prevH && W <= prevW && L <= prevL) { dp[i] = max(dp[j] + H, dp[i]); }
            }
        }

        return *max_element(dp, dp + 102);
    }
};
