class Solution
{
public:
    long long maxPoints(vector<int> &technique1, vector<int> &technique2, int k)
    {
        int n = technique1.size();
        vector<pair<int, int>> diffs(n);
        for (int i = 0; i < n; ++i)
        {
            diffs[i] = {technique1[i] - technique2[i], i};
        }
        sort(diffs.begin(), diffs.end(), greater<>());
        vector<int> done(n, 0);
        long long ret = 0;
        while (k--)
        {
            auto idx = diffs[k].second;
            ret += technique1[idx];
            done[idx] = 1;
        }
        for (int i = 0; i < n; ++i)
        {
            if (done[i])
            {
                continue;
            }
            ret += max(technique1[i], technique2[i]);
        }
        return ret;
    }
};
