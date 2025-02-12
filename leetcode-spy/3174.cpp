class Solution
{
public:
    string clearDigits(string s)
    {
        string ret;
        for (int i = 0; i < s.size();)
        {
            char c = s[i];
            if (0 <= c - '0' && c - '0' <= 9)
            {
                if (!ret.empty())
                {
                    ret.pop_back();
                }
                ++i;
            }
            else
            {
                ret.push_back(c);
                ++i;
            }
        }
        return ret;
    }
};
