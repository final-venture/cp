class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        // Choose two parts: nums[i:j] and nums[k:l], where i, j, k, l in range of array
        // Optimise for 2 subarrays with largest total length whose sum is divisible by p
        // OR
        // FIND length of smallest subarray whose subSum % p = totalSum % p        <----      THIS ONE SEEMS EASIER

        // FIND i < j in pfx where (pfx[j] - pfx[i]) % p == reqRem;
        // so (pfx[j] - pfx[i]) == reqRem + k*p

        // [6, 3, 5, 2] --> [0, 6, 9, 14, 16]
        //                  [0, 6, 0, 5, 7]
        // reqRem = 7, p = 9
        // pick min dist j and i where their difference has remainder 7 when divided by 9
        // need 7, 16, 25, 34 ...

        // [3, 1, 4, 2] --> [0, 3, 4, 8, 10]
        //                  [0, 3, 4, 2, 4]
        // reqRem = 10, p = 6

        int n = nums.size();
        int reqRem = 0;
        for (int i = 0; i < n; ++i)
        {
            reqRem += nums[i];
            reqRem %= p;
        }
        if (!reqRem)
            return 0;

        // cout << reqRem << '\n';

        unordered_map<int, int> lastIdx;
        lastIdx[0] = -1;
        int pfx = 0;
        int ret = n;
        for (int i = 0; i < n; ++i)
        {
            pfx += nums[i];
            pfx %= p;
            int toFind = (pfx + p - reqRem) % p;
            if (lastIdx.find(toFind) != lastIdx.end())
            {
                ret = min(ret, i - lastIdx[toFind]);
            }
            // cout << pfx << ' ';
            lastIdx[pfx] = i;
        }
        return (ret == n) ? -1 : ret;
    }
};
