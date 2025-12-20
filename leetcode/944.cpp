class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size(), m = strs[0].size();
        if (n <= 1)
        {
            return 0;
        }
        int ret = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (strs[j][i] < strs[j - 1][i])
                {
                    ++ret;
                    break;
                }
            }
        }
        return ret;
    }
};
