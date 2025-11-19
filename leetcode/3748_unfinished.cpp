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
        vector<int> sscnts(sn);
        vector<int> sssfx(sn, 0);
        vector<int> sspfx(sn, 0);

        for (int i = 0; i < sn; ++i)
        {
            int L = ends[i] - starts[i] + 1;
            sscnts[i] = L * (L + 1) / 2;
        }
        for (int i = sn - 2; i >= 0; --i)
        {
            sssfx[i] = sssfx[i + 1] + sscnts[i + 1];
        }
        for (int i = 1; i < sn; ++i)
        {
            sspfx[i] = sspfx[i - 1] + sscnts[i - 1];
        }

        debug(sn, starts);
        debug(sn, ends);
        debug(sn, sspfx);
        debug(sn, sssfx);

        vector<long long> rets(qn, sssfx[0] + sscnts[0]);
        for (int i = 0; i < qn; ++i)
        {
            auto &q = queries[i];
            int st = q[0], ed = q[1];
            int startsIdx = lower_bound(starts.begin(), starts.end(), st) - starts.begin();
            int endsIdx = lower_bound(ends.begin(), ends.end(), ed) - ends.begin();
            rets[i] -= sspfx[startsIdx];
            rets[i] -= sssfx[endsIdx];
            rets[i] -= (st - starts[startsIdx]);
            rets[i] -= (ends[endsIdx] - ed);
        }

        return rets;
    }
};
