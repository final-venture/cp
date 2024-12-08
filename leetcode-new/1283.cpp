class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r)
        {
            int m = l + ((r - l) >> 1);
            int acu = 0;
            for (int x : nums)
            {
                acu += (x + m - 1) / m;
                if (acu > threshold) break;
            }
            if (acu <= threshold) r = m;
            else l = m + 1;
        }
        return l;
    }
};
