class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long ret = 0, n = happiness.size();
        sort(happiness.begin(), happiness.end());
        for (int i = n - 1, curr = 0; i >= 0 && curr < k; --i, ++curr)
        {
            ret += max(0, happiness[i] - curr);
        }
        return ret;
    }
};
