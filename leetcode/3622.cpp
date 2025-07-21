class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int digit_product = 1;
        int curr = n;
        while (curr)
        {
            int d = curr % 10;
            digit_product *= d;
            if (digit_product > n)
            {
                return false;
            }
            curr /= 10;
        }
        int digit_sum = 0;
        curr = n;
        while (curr)
        {
            int d = curr % 10;
            digit_sum += d;
            curr /= 10;
        }
        if ((n % (digit_sum + digit_product)) == 0)
        {
            return true;
        }
        return false;
    }
};