// O(kn) DP - Tight AC
class Solution
{
private:
    vector<int> nums;
    int n, k, start_bal;
    long long dp[1001][2001][3];

public:
    // start_bal is even balance
    long long solve(int i, int picks, int balance)
    {
        if (picks > 2 * k)
        {
            return -1e18;
        }
        if (i >= n)
        {
            // cout << i << ' ' << picks << ' ' << balance << '\n';
            return balance == start_bal ? 0 : -1e18;
        }
        if (dp[i][picks][balance] != -1)
        {
            return dp[i][picks][balance];
        }

        long long pickAdd = -1e18, pickMinus = -1e18;
        if (balance + 1 <= 2)
        {
            pickAdd = nums[i] + solve(i + 1, picks + 1, balance + 1);
        }
        if (balance - 1 >= 0)
        {
            pickMinus = -nums[i] + solve(i + 1, picks + 1, balance - 1);
        }
        long long pickNothing = solve(i + 1, picks, balance); // PICK NOTHING
        long long ret = pickNothing;

        if (pickAdd > ret)
            ret = pickAdd;
        if (pickMinus > ret)
            ret = pickMinus;
        return dp[i][picks][balance] = ret;
    }

    long long maximumScore(vector<int> &nums, int k)
    {
        n = nums.size();
        if (n == 1)
            return 0;
        this->k = k;
        this->nums = nums;

        long long ret = 0;
        for (; start_bal < 3; ++start_bal)
        {
            for (int i = 0; i <= n; ++i)
            {
                for (int j = 0; j <= 2 * k; ++j)
                {
                    dp[i][j][0] = -1;
                    dp[i][j][1] = -1;
                    dp[i][j][2] = -1;
                }
            }
            ret = max(ret, solve(0, 0, start_bal));
        }

        return ret;
    }
};

// O(k*n^3) DP - TLE
class Solution
{
private:
    vector<int> nums;
    int n;
    int k;
    vector<vector<long long>> rangeOf;
    vector<vector<vector<long long>>> dp;

public:
    int normalise(int i)
    {
        return i % n;
    }

    long long solve(int i, int j, int start)
    {
        if (j >= k)
        {
            return INT_MIN;
        }
        if (dp[i][j][start] != -1)
        {
            return dp[i][j][start];
        }
        long long ret = 0;
        for (int z = i + 1; normalise(z) != normalise(start + n); ++z)
        {
            int nxtIdx = normalise(z);
            if (normalise(z + 1) != start)
            {
                ret = max(ret, rangeOf[i][nxtIdx] + solve(normalise(z + 1), j + 1, start));
            }
            else
            {
                ret = max(ret, rangeOf[i][nxtIdx]);
            }
        }
        // cout << i << ' ' << j << ' ' << start << ' ' << ret << '\n';
        return dp[i][j][start] = ret;
    }

    long long maximumScore(vector<int> &nums, int k)
    {
        n = nums.size();
        if (n == 1)
            return 0;
        this->k = k;
        this->nums = nums;
        rangeOf.resize(n, vector<long long>(n));
        dp.resize(n + 1, vector<vector<long long>>(k + 1, vector<long long>(n + 1, -1)));
        for (int i = 0; i < n; ++i)
        {
            int currMax = 0, currMin = 1e9 + 5;
            for (int j = i; j < i + n; ++j)
            {
                int normIndex = normalise(j);
                // cout << i << ' ' << normIndex << endl;
                currMax = max(currMax, nums[normIndex]), currMin = min(currMin, nums[normIndex]);
                rangeOf[i][normIndex] = currMax - currMin;
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << rangeOf[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        long long ret = 0;
        for (int i = 0; i < n; ++i)
        {
            ret = max(ret, solve(i, 0, i));
        }
        return ret;
    }
};
