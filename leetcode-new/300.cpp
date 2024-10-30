// O(n) dp
class Solution
{
public:
    int lengthOfLIS(vector<int> &vec)
    {
        int n = vec.size();
        vector<int> dp(n, 1);
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (vec[j] > vec[i])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// O(nlogn) binary search + greedy
class Solution
{
public:
    int lengthOfLIS(vector<int> &vec)
    {
        int n = vec.size();
        vector<int> cands;
        for (int x : vec)
        {
            if (cands.empty() || x > cands[cands.size() - 1])
            {
                cands.push_back(x);
            }
            else
            {
                auto it = lower_bound(cands.begin(), cands.end(), x);
                *it = x;
            }
        }
        return cands.size();
    }
};
