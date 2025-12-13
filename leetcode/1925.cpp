class Solution
{
public:
    int countTriples(int n)
    {
        unordered_set<int> squares;
        for (int i = 1; i <= n; ++i)
        {
            squares.insert(i * i);
        }
        int ret = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; ++j)
            {
                int cand = i * i + j * j;
                if (squares.contains(cand))
                {
                    ret += 2;
                }
            }
        }
        return ret;
    }
};
