class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MAX;
        long long currSum = 0;
        vector<long long> pfxs {LLONG_MIN};
        vector<int> pfxi { -1};
        for (int i = 0; i < n; ++i)
        {
            currSum += nums[i];
            while (!pfxs.empty() && currSum <= pfxs.back())
            {
                pfxs.pop_back();
                pfxi.pop_back();
            }
            pfxs.push_back(currSum);
            pfxi.push_back(i);
            int tmp = upper_bound(pfxs.begin(), pfxs.end(), currSum - k) - pfxs.begin();
            // for (auto& x : pfxs) cout << x << ' ';
            // cout << endl;
            // cout << currSum - k << endl;
            // cout << tmp << endl;
            int candidx = pfxi[tmp - 1];
            if (candidx != -1)
            {
                res = min(res, i - candidx);
            }
            else
            {
                if (currSum >= k)
                    res = min(res, i + 1);
            }
        }
        return (res == INT_MAX) ? -1 : res;
    }
};
