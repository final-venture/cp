class Solution
{
public:
    int countPermutations(vector<int> &complexity)
    {
        int n = complexity.size();
        for (int i = 1; i < n; ++i)
        {
            if (complexity[i] <= complexity[0])
            {
                return 0;
            }
        }
        long long ret = 1;
        const int MOD = 1e9 + 7;
        for (long long i = n - 1; i >= 1; --i)
        {
            ret *= i;
            ret %= MOD;
        }
        return ret;
    }
};
