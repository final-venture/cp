class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;
        int maxx = 0;
        while (i < j)
        {
            int currh = (j - i) * min(height[j], height[i]);
            maxx = max(maxx, currh);
            if (height[j] < height[i])
                --j;
            else
                ++i;
        }
        return maxx;
    }
};
