class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long ret = 0;
        int n = matrix.size(), m = matrix[0].size();
        bool hasZero = false;
        int absMin = INT_MAX;
        int negCnt = 0;
        vector<int> neg;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] < 0)
                {
                    ++negCnt;
                }
                if (matrix[i][j] == 0)
                {
                    hasZero = true;
                }
                ret += abs(matrix[i][j]);
                absMin = min(absMin, abs(matrix[i][j]));
            }
        }
        if (!hasZero && (negCnt & 1))
        {
            ret -= 2 * absMin;
        }
        return ret;
    }
};
