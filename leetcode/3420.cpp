#define ll long long
class Solution
{
public:
    long long countNonDecreasingSubarrays(vector<int> &nums, ll k)
    {
        int n = nums.size();
        ll ret = 0;
        deque<int> dq;
        reverse(nums.begin(), nums.end());
        int i = 0;
        for (int j = 0; j < n; ++j)
        {
            while (!dq.empty() && nums[dq.back()] < nums[j])
            {
                int rgt = dq.back();
                dq.pop_back();
                int lft = (dq.empty()) ? i - 1 : dq.back();
                k -= 1LL * (rgt - lft) * (nums[j] - nums[rgt]);
            }
            dq.push_back(j);
            while (k < 0)
            {
                k += (nums[dq.front()] - nums[i]);
                if (i == dq.front())
                {
                    dq.pop_front();
                }
                ++i;
            }
            ret += j - i + 1;
        }
        return ret;
    }
};
