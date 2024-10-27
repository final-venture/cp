class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        int n = height.size();
        if (n == 1)
            return 0;

        int i = 0;
        int j = 0;
        int rt = 0;
        while (++j < n)
        {
            if (height[j] >= height[i])
            {
                res += rt;
                rt = 0;
                i = j;
            }
            else
                rt += height[i] - height[j];
        }

        int sp = i;
        i = n - 1;
        j = n - 1;
        rt = 0;
        while (--i >= sp)
        {
            if (height[i] >= height[j])
            {
                res += rt;
                rt = 0;
                j = i;
            }
            else
                rt += height[j] - height[i];
        }
        return res;
    }
};
