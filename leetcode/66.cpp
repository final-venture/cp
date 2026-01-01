class Solution
{
private:
    vector<int> digits;
    void increment(int i)
    {
        digits[i]++;
        if (digits[i] == 10)
        {
            digits[i] = 0;
            if (i <= 0)
            {
                digits.insert(digits.begin(), 1);
            }
            else
            {
                increment(i - 1);
            }
        }
    }

public:
    vector<int> plusOne(vector<int> &digits)
    {
        this->digits = digits;
        increment(digits.size() - 1);
        return this->digits;
    }
};
