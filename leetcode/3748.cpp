#define debug(ub, x)             \
    cout << #x << ": ";          \
    for (int i = 0; i < ub; ++i) \
    {                            \
        cout << (x)[i] << ' ';   \
    }                            \
    cout << '\n';
class Solution
{
public:
    vector<long long> countStableSubarrays(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> starts;
        vector<int> ends;

        int nn = nums.size(), qn = queries.size();
        for (int i = 0; i < nn; ++i)
        {
            if (starts.size() == ends.size())
            {
                starts.push_back(i);
            }
            int next = (i == nn - 1) ? INT_MIN : nums[i + 1];
            if (nums[i] > next)
            {
                ends.push_back(i);
            }
        }
        // if (starts.size() != ends.size()) ends.push_back(nn - 1);

        int sn = starts.size();
        vector<long long> sscnts(sn);
        vector<long long> sspfx(sn, 0);
        // vector<long long> sssfx(sn, 0);

        for (int i = 0; i < sn; ++i)
        {
            long long L = ends[i] - starts[i] + 1;
            sscnts[i] = L * (L + 1) / 2;
        }

        // for (int i = sn - 2; i >= 0; --i) {
        //     sssfx[i] = sssfx[i + 1] + sscnts[i + 1];
        // }

        for (int i = 1; i < sn; ++i)
        {
            sspfx[i] = sspfx[i - 1] + sscnts[i - 1];
        }

        // debug(sn, starts);
        // debug(sn, ends);
        // debug(sn, sscnts);
        // debug(sn, sspfx);
        // debug(sn, sssfx);

        vector<long long> rets(qn, 0);
        for (int i = 0; i < qn; ++i)
        {
            auto &q = queries[i];
            int st = q[0], ed = q[1];
            int endsIdx1 = lower_bound(ends.begin(), ends.end(), st) - ends.begin();
            int endsIdx2 = lower_bound(ends.begin(), ends.end(), ed) - ends.begin();
            if (endsIdx1 == endsIdx2)
            {
                long long L = ed - st + 1;
                rets[i] += L * (L + 1) / 2;
            }
            else
            {
                rets[i] += sspfx[endsIdx2] - sspfx[endsIdx1] - sscnts[endsIdx1];
                long long L1 = ends[endsIdx1] - st + 1, L2 = ed - starts[endsIdx2] + 1;
                rets[i] += L1 * (L1 + 1) / 2;
                rets[i] += L2 * (L2 + 1) / 2;
            }
        }

        return rets;
    }
};
