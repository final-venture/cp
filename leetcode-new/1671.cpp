class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        int minremoved = INT_MAX;
        for (int maxp = 1; maxp < nums.size() - 1; ++maxp)
        {
            int currremoved = 0;
            int lstidx = 0;
            for (int l = 1; l <= maxp; ++l) // remove from increasing portion
            {
                if (nums[lstidx] >= nums[maxp] || nums[lstidx] >= nums[l])
                {
                    ++currremoved;
                }
                else
                {
                    lstidx = l;
                }
            }
            lstidx = 0;
            for (int r = n - 2; r >= maxp; --r) // remove from decreasing portion
            {
                if (nums[lstidx] >= nums[maxp] || nums[lstidx] >= nums[r])
                {
                    ++currremoved;
                }
                else
                {
                    lstidx = r;
                }
            }
            if (currremoved <= minremoved) // debug
            {
                cout << maxp << endl;
            }
            minremoved = min(minremoved, currremoved);
        }
        return minremoved;
    }
};
