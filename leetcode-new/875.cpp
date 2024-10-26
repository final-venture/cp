class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r)
        {
            int m = (r + l) >> 1;
            if (helper(piles, h, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }

    int helper(vector<int> &piles, int &h, int s)
    {
        int time = 0;
        for (auto b : piles)
        {
            if (s >= b)
                time++;
            else
                time += ((b % s) ? b / s + 1 : b / s);
            if (time > h)
                return false;
        }
        return true;
    }
};
