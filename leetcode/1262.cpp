class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        int summ = accumulate(nums.begin(), nums.end(), 0);
        vector<int> mod1;
        vector<int> mod2;

        for (auto num : nums)
        {
            if (num % 3 == 1)
            {
                mod1.push_back(num);
            }
            else if (num % 3 == 2)
            {
                mod2.push_back(num);
            }
        }

        sort(mod1.begin(), mod1.end());
        sort(mod2.begin(), mod2.end());
        int ret = 0;

        if (summ % 3 == 0)
        {
            return summ;
        }
        else if (summ % 3 == 1)
        {
            if (mod2.size() >= 2)
            {
                ret = max(summ - mod2[0] - mod2[1], ret);
            }
            if (!mod1.empty())
            {
                ret = max(ret, summ - mod1[0]);
            }
        }
        else if (summ % 3 == 2)
        {
            if (mod1.size() >= 2)
            {
                ret = max(summ - mod1[0] - mod1[1], ret);
            }
            if (!mod2.empty())
            {
                ret = max(ret, summ - mod2[0]);
            }
        }
        return ret;
    }
};
