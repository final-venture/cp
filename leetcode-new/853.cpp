class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int res = 0;
        vector<pair<int, int>> ps;
        for (int i = 0; i < position.size(); i++)
            ps.push_back({-position[i], speed[i]});
        sort(ps.begin(), ps.end());
        double lt = 0;
        for (auto &[p, s] : ps)
        {
            double ntt = (target + p) / static_cast<double>(s);
            if (ntt > lt)
            {
                lt = ntt;
                res++;
            }
        }
        return res;
    }
};
