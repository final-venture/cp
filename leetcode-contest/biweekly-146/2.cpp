// ?????????
#define MOD 1000000007
#define ll long long
class Solution {
private:
    ll m;
    ll n;
    ll k;
    vector<vector<vector<ll>>> dp;
    vector<vector<int>> grid;
    const ll LOG = 23;
public:
    ll dfs(ll r, ll c, int state)
    {
        if (r == m - 1 && c == n - 1 && state == k) return 1;
        if (dp[r][c][state] != -1) return dp[r][c][state];

        if (r < m - 1)
        {
            dp[r][c][state] += dfs(r + 1, c, state ^ grid[r + 1][c]);
            dp[r][c][state] %= MOD;
        }
        if (c < n - 1)
        {
            dp[r][c][state] += dfs(r, c + 1, state ^ grid[r][c + 1]);
            dp[r][c][state] %= MOD;
        }

        return dp[r][c][state];
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        this -> grid = grid;
        this -> k = k;
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<vector<ll>>(n, vector<ll>(LOG, -1)));
        dfs(0, 0, grid[0][0]);
        return (int) dp[0][0][grid[0][0]];
    }
};
©leetcode