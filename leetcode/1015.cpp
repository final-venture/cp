class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        // when you add 1 to num, its just num * 10 + 1
        // hypothesis: just mod it
        string kStr = to_string(k);
        int last_digit = kStr[kStr.size() - 1] - '0';
        if (last_digit != 1 && last_digit != 3 && last_digit != 7 && last_digit != 9)
        {
            return -1;
        }
        int num = 1;
        int length = 1;
        while (num % k != 0)
        {
            num *= 10;
            num += 1;
            num %= k;
            ++length;
        }
        return length;
    }
};
