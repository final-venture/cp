class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        set<int> numset(nums.begin(), nums.end());
        unordered_set<int> seen;
        int longest = -1;
        for (int val : numset)
        {
            if (seen.find(val) != seen.end())
                continue;
            int length = 0;
            while (numset.find(val) != numset.end())
            {
                ++length;
                if (val > 5000)
                    break;
                val *= val;
            }
            longest = max(longest, length);
        }
        return (longest > 1) ? longest : -1;
    }
};
