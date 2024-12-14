class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ret;
        int n = s.size();
        unordered_map<char, int> c2i;
        for (int i = 0; i < n; ++i)
        {
            ++c2i[s[i]];
        }
        char ban = '!';
        int ok = 1;
        char lst = '!';
        int rep = 1;
        while (ok)
        {
            for (char c = 'z'; c >= 'a' - 1; --c)
            {
                if (c == 'a' - 1)
                {
                    ok = 0;
                    break;
                }
                if (!c2i[c]) continue;
                if (lst == c)
                {
                    ++rep;
                    if (rep > repeatLimit)
                    {
                        continue;
                    }
                }
                else
                {
                    lst = c;
                    rep = 1;
                    ban = '!';
                }
                --c2i[c];
                ret += c;
                break;
            }
        }
        return ret;
    }
};
