class Solution
{
private:
    vector<int> generatePalindromes()
    {
        vector<bool> isPals(5555);
        for (int i = 1; i <= 5555; ++i)
        {
            int l = log2(i), r = 0;
            bool isPal = true;
            while (l > r)
            {
                if ((i >> l & 1) != (i >> r & 1))
                {
                    isPal = false;
                    break;
                }
                --l;
                ++r;
            }
            isPals[i] = isPal;
        }
        vector<int> ret;
        for (int i = 1; i <= 5555; ++i)
        {
            if (isPals[i])
            {
                ret.push_back(i);
            }
        }
        return ret;
    }

public:
    vector<int> minOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> palindromes = generatePalindromes();
        sort(palindromes.begin(), palindromes.end());
        // cout << palindromes[139] << ' ' << palindromes[140] << '\n';
        vector<int> ret(n);
        for (int i = 0; i < n; ++i)
        {
            auto idx = lower_bound(palindromes.begin(), palindromes.end(), nums[i]) - palindromes.begin();
            // if (i == 1) {
            //     cout << idx;
            // }
            int nearest = (idx == 0) ? palindromes[idx] - nums[i] : min(palindromes[idx] - nums[i], nums[i] - palindromes[idx - 1]);
            ret[i] = nearest;
        }
        return ret;
    }
};
