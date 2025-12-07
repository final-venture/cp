class Solution
{
private:
    bool isPrime(int n)
    {
        if (n == 1)
        {
            return false;
        }
        if (n == 2)
        {
            return true;
        }
        if (n % 2 == 0)
        {
            return false;
        }
        bool ret = true;
        for (long long i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                ret = false;
                break;
            }
        }
        return ret;
    }

public:
    bool completePrime(int num)
    {
        string numStr = to_string(num);
        int cand = 0;
        int curr_digit = 1;
        for (int i = numStr.size() - 1; i >= 0; --i)
        {
            cand += (numStr[i] - '0') * curr_digit;
            curr_digit *= 10;
            // cout << cand << ' ';
            if (!isPrime(cand))
            {
                return false;
            }
        }
        // cout << '\n';
        cand = 0;
        for (int i = 0; i < numStr.size(); ++i)
        {
            cand = cand * 10 + (numStr[i] - '0');
            // cout << cand << ' ';
            if (!isPrime(cand))
            {
                return false;
            }
        }
        return true;
    }
};
