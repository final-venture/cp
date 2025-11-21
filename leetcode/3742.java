class Solution {
    private int[][] grid;
    private int[][][] dp;
    private final int[][] v2sc = {
            {0, 0},
            {1, 1},
            {2, 1}
    };
    private int m;
    private int n;
    private int k;

    public boolean valid(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        return true;
    }

    public int dfs(int i, int j, int z) {
        // if (!valid(i, j)) {
        //     return 0;
        // }
        // System.out.println(i + ", " + j + ", " + z);

        if (z > k) {
            // System.out.println(i + ", " + j + ", " + z);
            return (int)(-1e6);
        }
        if (i == m - 1 && j == n - 1) {
            return v2sc[grid[i][j]][0];
        }
        if (dp[i][j][z] != -1) {
            return dp[i][j][z];
        }
        
        int ret = v2sc[grid[i][j]][0];
        int cand = (int)(-1e6);
        if (valid(i + 1, j)) {
            int val = grid[i + 1][j];
            int nxt = dfs(i + 1, j, z + v2sc[val][1]);
            cand = Math.max(nxt, cand);
        }
        if (valid(i, j + 1)) {
            int val = grid[i][j + 1];
            int nxt = dfs(i, j + 1, z + v2sc[val][1]);
            cand = Math.max(nxt, cand);
        }
        ret += cand;

        // System.out.println(i + ", " + j + ", " + z + ", " + ret);
        return dp[i][j][z] = ret;
    }
    
    public int maxPathScore(int[][] gridd, int k) {
        this.grid = gridd;
        this.k = k;
        m = grid.length; n = grid[0].length;
        dp = new int[m + 1][n + 1][k + 1];

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int z = 0; z <= k; ++z) {
                    dp[i][j][z] = -1;
                }
            }
        }

        int ret = dfs(0, 0, v2sc[grid[0][0]][1]);
        return (ret < 0) ? -1 : ret;
    }
}
