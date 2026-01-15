class Solution
{
private:
    bool isEqual(vector<int> &v1, vector<int> &v2)
    {
        int n = v1.size();
        for (int i = 0; i < n; ++i)
        {
            if (v1[i] != v2[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    long long countPairs(vector<string> &words)
    {
        int n = words.size(), m = words[0].size();
        vector<vector<int>> d(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if (words[i][j] - words[i][j - 1] >= 0)
                {
                    d[i][j] = words[i][j] - words[i][j - 1];
                }
                else
                {
                    d[i][j] = words[i][j] - words[i][j - 1] + 26;
                }
            }
        }
        sort(d.begin(), d.end());
        long long run = 1, ret = 0;
        for (int i = 1; i < n; ++i)
        {
            if (isEqual(d[i], d[i - 1]))
            {
                ++run;
            }
            else
            {
                ret += run * (run - 1) / 2;
                run = 1;
            }
        }
        ret += run * (run - 1) / 2;
        return ret;
    }
};
