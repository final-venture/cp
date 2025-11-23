class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        string numStr = to_string(n);
        int nn = numStr.size();
        string retStr;
        long long sumDigits = 0;
        for (int i = 0; i < nn; ++i)
        {
            if (numStr[i] == '0')
            {
                continue;
            }
            sumDigits += (numStr[i] - '0');
            retStr.push_back(numStr[i]);
        }
        return (retStr.size() == 0) ? 0 : stoll(retStr) * sumDigits;
    }
};
