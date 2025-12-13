class Solution
{
public:
    int countOdds(int low, int high)
    {
        int ret = 0;
        if (low & 1 || high & 1)
            ++ret;
        ret += (high - low) / 2;
        return ret;
    }
};
