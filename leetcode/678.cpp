class Solution
{
public:
    bool checkValidString(string s)
    {
        int minopen = 0, maxopen = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                ++minopen;
                ++maxopen;
            }
            if (c == ')')
            {
                --minopen;
                --maxopen;
            }
            if (c == '*')
            {
                --minopen;
                ++maxopen;
            }
            if (maxopen < 0)
                return false;
            if (minopen < 0)
                minopen = 0;
        }
        return minopen == 0;
    }
};
