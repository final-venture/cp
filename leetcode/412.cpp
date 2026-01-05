class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ret(n);
        for (int i = 0; i < n; ++i)
        {
            int num = i + 1;
            if (num % 3 == 0 && num % 5 == 0)
            {
                ret[i] = "FizzBuzz";
            }
            else if (num % 3 == 0)
            {
                ret[i] = "Fizz";
            }
            else if (num % 5 == 0)
            {
                ret[i] = "Buzz";
            }
            else
            {
                ret[i] = to_string(num);
            }
        }
        return ret;
    }
};
