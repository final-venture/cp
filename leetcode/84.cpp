class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> mds;
        mds.push_back(-1);
        int ma = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (mds.back() != -1 && heights[i] < heights[mds.back()])
            {
                int h = heights[mds.back()];
                mds.pop_back();
                int w = (i - mds.back() - 1);
                ma = max(ma, h * w);
            }
            mds.push_back(i);
        }

        while (mds.back() != -1)
        {
            int h = heights[mds.back()];
            mds.pop_back();
            int w = (heights.size() - mds.back() - 1);
            ma = max(ma, h * w);
        }

        return ma;
    }
};
