class Solution
{
private:
    int c2n(char c)
    {
        return c - 'a';
    }

    char n2c(int idx)
    {
        return static_cast<char>('a' + idx);
    }

public:
    string robotWithString(string s)
    {
        int n = s.size();
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
        {
            nums[i] = c2n(s[i]);
        }
        string t;
        vector<int> rgtSmallest(nums.begin(), nums.end());
        for (int i = n - 2; i >= 0; --i)
        {
            rgtSmallest[i] = min(rgtSmallest[i + 1], rgtSmallest[i]);
        }

        string ret;
        vector<int> numsQ;
        for (int i = 0; i < n; ++i)
        {
            while (!numsQ.empty() && rgtSmallest[i] >= numsQ.back())
            {
                ret.push_back(n2c(numsQ.back()));
                numsQ.pop_back();
            }
            if (nums[i] <= rgtSmallest[i]) // if this is the smallest closest to left
            {
                ret.push_back(n2c(nums[i]));
            }
            else
            {
                numsQ.push_back(nums[i]);
            }
        }
        while (!numsQ.empty())
        {
            ret.push_back(n2c(numsQ.back()));
            numsQ.pop_back();
        }
        return ret;
    }
};
