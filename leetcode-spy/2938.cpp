class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long res = 0;
        int count_ones = 0;
        for (char c : s)
        {
            if (c == '1')
            {
                count_ones++;
            }
            else
            {
                res += count_ones;
            }
        }
        return res;
    }
};
