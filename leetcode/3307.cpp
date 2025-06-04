class Solution {
public:
    char advance(char c)
    {
        int x = c - 'a';
        return ((x + 1) % 26) + 'a';
    }
    char kthCharacter(long long k, vector<int>& operations) {
        --k;
        int LOG = min(48, static_cast<int>(operations.size()));
        int ret = 'a';
        for (int i = LOG - 1; i >= 0; --i)
        {
            if (operations[i] && (k & (1ll << i)))
            {
                ret = advance(ret);
            }
        }
        return ret;
    }
};
