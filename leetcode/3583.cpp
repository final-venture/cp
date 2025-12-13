class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        const int MOD = 1e9 + 7;
        int totalCnts[100005], prevCnts[100005];
        memset(totalCnts, 0, sizeof totalCnts);
        memset(prevCnts, 0, sizeof prevCnts);
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            totalCnts[nums[i]]++;
        }

        long long ret = 0;
        for (int i = 0; i < n; ++i)
        {
            int target = nums[i] * 2;
            if (target <= 100002)
            {
                long long prevCnt = prevCnts[target];
                prevCnts[nums[i]]++;
                long long futureCnt = totalCnts[target] - prevCnts[target];
                ret += prevCnt * futureCnt;
                ret %= MOD;
            }
            else
            {
                prevCnts[nums[i]]++;
            }
        }

        return ret;
    }
};
