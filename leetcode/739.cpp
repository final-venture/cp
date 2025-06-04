class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size(), 0);
        vector<int> mds;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!mds.empty() && temperatures[i] > temperatures[mds.back()])
            {
                res[mds.back()] = i - mds.back();
                mds.pop_back();
            }
            mds.push_back(i);
        }
        return res;
    }
};
