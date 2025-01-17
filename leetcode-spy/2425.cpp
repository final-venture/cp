class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        int ret = 0;
        if (n1 & 1)
        {
            for (int i = 0; i < n2; ++i)
            {
                ret ^= nums2[i];
            }
        }
        if (n2 & 1)
        {
            for (int i = 0; i < n1; ++i)
            {
                ret ^= nums1[i];
            }
        }
        return ret;
    }
};
