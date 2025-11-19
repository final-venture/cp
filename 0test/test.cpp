#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
private:
    vector<long long> cntw0;

    long long power(int base, int exp)
    {
        long long res = 1;
        // Handle exp = 0 case
        if (exp == 0)
            return 1;
        for (int i = 0; i < exp; ++i)
        {
            res *= base;
        }
        return res;
    }

    long long countWithZeros(long long n)
    {
        string s = to_string(n);
        int len = s.length();
        long long res = 0;

        // 1. Add counts for all numbers with *fewer digits* than n.
        //    Your cntw0[i] already has this pre-calculated.
        for (int i = 1; i < len; ++i)
        {
            res += cntw0[i];
        }

        // 2. Count numbers with the *same number of digits* (len) up to n.
        //    We iterate through the digits of 'n' from left to right.
        bool hasZeroSoFar = false; // Tracks if the prefix of 'n' has a zero

        for (int i = 0; i < len; ++i)
        {
            int digit = s[i] - '0';

            // 'start' is 1 for the first digit (can't be 0), else 0
            int start = (i == 0) ? 1 : 0;

            // Iterate for all digits 'd' *less than* the current 'digit'
            // This is the "non-tight" path.
            for (int d = start; d < digit; ++d)
            {
                int remaining_digits = len - 1 - i;

                if (hasZeroSoFar || d == 0)
                {
                    // If the prefix (e.g., "10_") or current digit ("10_") has a zero,
                    // all possible suffixes are valid.
                    res += power(10, remaining_digits);
                }
                else
                {
                    // The prefix (e.g., "12_") has no zeros.
                    // We must count suffixes *with* at least one zero.
                    // Total suffixes = 10^rem
                    // Suffixes with NO zeros = 9^rem
                    res += (power(10, remaining_digits) - power(9, remaining_digits));
                }
            }

            // Update 'hasZeroSoFar' for the "tight" path
            if (digit == 0)
            {
                hasZeroSoFar = true;
            }
        }

        // 3. Finally, check 'n' itself.
        //    The loop only counted numbers *less than* n.
        if (hasZeroSoFar)
        {
            res++; // 'n' itself has a zero, so count it.
        }

        return res;
    }

public:
    long long countDistinct(long long n)
    {
        // Your pre-calculation logic is correct.
        // Let's run it up to 18 (for n <= 10^15).
        cntw0.resize(20, 0);
        for (int i = 2; i <= 18; ++i)
        {
            long long free = power(10, i - 2);
            long long last = cntw0[i - 1];
            cntw0[i] = (free + last) * 9;
        }

        // 'ret' is the count of numbers <= n with at least one zero.
        long long ret = countWithZeros(n);

        // Your final formula is correct:
        // Total numbers = n
        // "Bad" numbers (with zeros) = ret
        // "Good" numbers (no zeros) = n - ret
        // The distinct set is exactly the "Good" numbers.
        return n - ret;
    }
};
