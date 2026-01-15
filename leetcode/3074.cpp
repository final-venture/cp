class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int m = capacity.size();
        sort(capacity.begin(), capacity.end(), greater<>());
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        int ret = 0;
        for (int i = 0; i < m && totalApples > 0; ++i)
        {
            totalApples -= capacity[i];
            ++ret;
        }
        return ret;
    }
};
