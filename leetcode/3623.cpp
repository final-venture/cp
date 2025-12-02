class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        const int MOD = 1e9 + 7;

        unordered_map<int, vector<int>> y2x;
        for (auto &p : points)
        {
            int x = p[0], y = p[1];
            y2x[y].push_back(x);
        }

        vector<long long> horiLineCnts;
        for (auto &p : y2x)
        {
            vector<int> &allX = p.second;
            long long sz = allX.size();
            long long horiLineCnt = sz * (sz - 1) / 2; // sz choose 2
            horiLineCnts.push_back(horiLineCnt);
        }

        // for (auto x : horiLineCnts) cout << x << ' ';
        // cout << '\n';

        int len = horiLineCnts.size();
        vector<long long> pfx(len + 1, 0);
        for (int i = 1; i <= len; ++i)
        {
            pfx[i] = pfx[i - 1] + horiLineCnts[i - 1];
            pfx[i] %= MOD;
        }

        // for (auto x : pfx) cout << x << ' ';
        // cout << '\n';

        long long ret = 0;
        for (int i = len; i >= 1; --i)
        {
            ret += (horiLineCnts[i - 1] * pfx[i - 1]);
            ret %= MOD;
        }
        return ret;
    }
};
