#define MOD 1000000007
#define ll long long
class Solution
{
private:
    vector<vector<ll>> ncr;

public:
    void precompute_ncr(int n, int k)
    {
        ncr.resize(n + 1, vector<ll>(k + 1, 0));
        for (int i = 0; i < n + 1; ++i)
        {
            ncr[i][0] = 1;
        }
        for (int x = 1; x < k + 1; ++x)
        {
            ncr[x][x] = 1;
        }
        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 1; j < k + 1; ++j)
            {
                ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
                ncr[i][j] %= MOD;
            }
        }
    }

    int minMaxSums(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        precompute_ncr(n, k);
        ll ret = 0;
        for (int i = 0; i < n; ++i)
        {
            int revI = n - i - 1;
            for (int j1 = 0; j1 < k; ++j1)
            {
                // cout << i << ' ' << j1 << '\n';
                ret += (ncr[i][j1] * nums[i]);
                ret %= MOD;
            }
            for (int j2 = 0; j2 < k; ++j2)
            {
                ret += (ncr[revI][j2] * nums[i]);
                ret %= MOD;
            }
        }
        return static_cast<int>(ret);
    }
};
