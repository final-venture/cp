class Solution
{
private:
    bool valid(vector<string> &strs)
    {
        for (int i = 0; i < strs.size() - 1; ++i)
        {
            if (strs[i] > strs[i + 1])
            {
                return false;
            }
        }
        return true;
    }

public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();
        int m = strs[0].size();

        vector<string> curr(n, "");
        int ret = 0;

        for (int col = 0; col < m; ++col)
        {
            vector<string> curr2 = curr;

            for (int i = 0; i < n; ++i)
            {
                curr2[i] += strs[i][col];
            }

            if (valid(curr2))
            {
                curr = curr2;
            }
            else
            {
                ret++;
            }
        }

        return ret;
    }
};
