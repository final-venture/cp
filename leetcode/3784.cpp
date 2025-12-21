class Solution
{
public:
    long long minCost(string s, vector<int> &cost)
    {
        int n = s.size();
        long long allCost = accumulate(cost.begin(), cost.end(), 0LL);
        vector<long long> char2cost(26, 0LL);
        for (int i = 0; i < n; ++i)
        {
            char2cost[s[i] - 'a'] += cost[i];
        }
        long long ret = LLONG_MAX;
        for (int i = 0; i < 26; ++i)
        {
            ret = min(ret, allCost - char2cost[i]);
        }
        return ret;
    }
};
