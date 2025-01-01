class Solution {
public:
    char advance(char c)
    {
        int x = c - 'a';
        return ((x + 1) % 26) + 'a';
    }
    char kthCharacter(long long k) {
        --k;
        int LOG = 10;
        int ret = 'a';
        for (int i = LOG - 1; i >= 0; --i)
        {
            if (k & (1ll << i))
            {
                ret = advance(ret);
            }
        }
        return ret;
    }
};
