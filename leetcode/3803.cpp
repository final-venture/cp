class Solution
{
public:
    int residuePrefixes(string s)
    {
        int n = s.size();
        unordered_set<char> charSet;
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            int curr = (i + 1) % 3;
            charSet.insert(s[i]);
            if (charSet.size() == curr)
            {
                ++ret;
            }
        }
        return ret;
    }
};
