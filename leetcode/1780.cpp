class Solution {
public:
    int mod_exp(int base, int exp)
    {
        int result = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = (result * base);
            }
            base = (base * base);
            exp /= 2;
        }
        return result;
    }
    
    bool checkPowersOfThree(int n) {
        int curr = n;
        for (int i = 15; i >= 0; --i)
        {
            int tmp = mod_exp(3, i);
            if (curr >= tmp)
            {
                curr -= tmp;
            }
        }
        if (!curr)
        {
            return true;
        }
        return false;
    }
};
