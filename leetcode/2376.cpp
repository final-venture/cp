class Solution
{
private:
    string numStr;
    int sz;
    int dp[10][1 << 10][2][2];
    int dfs(int idx, int mask, int tight, int started)
    {
        if (idx >= sz)
        {
            return 1;
        }
        if (dp[idx][mask][tight][started] != -1)
        {
            return dp[idx][mask][tight][started];
        }
        int ub = tight ? numStr[idx] - '0' : 9;
        int ret = 0;
        for (int d = 0; d <= ub; ++d)
        {
            if (mask >> d & 1)
            {
                continue;
            }
            int newTight = tight && d == numStr[idx] - '0';
            int newStarted = started || d != 0;
            int newMask = newStarted ? mask | (1 << d) : mask;
            ret += dfs(idx + 1, newMask, newTight, newStarted);
        }
        return dp[idx][mask][tight][started] = ret;
    }

public:
    int countSpecialNumbers(int n)
    {
        numStr = to_string(n);
        sz = numStr.size();
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, 1, 0) - 1;
    }
};
