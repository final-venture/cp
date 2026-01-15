class Solution
{
public:
    int numberOfSteps(int num)
    {
        int ret = 0;
        while (num > 0)
        {
            if (num & 1)
            {
                --num;
            }
            else
            {
                num /= 2;
            }
            ++ret;
        }
        return ret;
    }
};
