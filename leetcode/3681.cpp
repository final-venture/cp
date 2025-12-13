class Solution
{
public:
    int maxXorSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> basis(32, 0);
        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            for (int bit = 31; bit >= 0; --bit)
            {
                if (num == 0)
                {
                    break;
                }
                if ((num >> bit) & 1)
                {
                    if (basis[bit] == 0)
                    {
                        basis[bit] = num;
                        break;
                    }
                    else
                    {
                        num ^= basis[bit];
                    }
                }
            }
        }

        int maxx = 0;
        for (int i = 31; i >= 0; --i)
        {
            maxx = max(maxx, maxx ^ basis[i]);
        }
        return maxx;
    }
};
