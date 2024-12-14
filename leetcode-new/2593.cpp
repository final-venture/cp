#define ll long long
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> banned(n);
        ll ret = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        for (int i = 0; i < n; ++i)
        {
            pq.push({nums[i], i});
        }
        while (!pq.empty())
        {
            auto [num, idx] = pq.top();
            pq.pop();
            if (banned[idx]) continue;
            ret += num;
            for (int i = -1; i <= 1; ++i)
            {
                if (0 <= idx + i && idx + i < n)
                    banned[idx + i] = 1;
            }
        }
        return ret;
    }
};