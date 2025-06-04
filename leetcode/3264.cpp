#define pii pair<int, int>
#define vpii vector<pii>
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pii, vpii, greater<>> pq;
        for (int i = 0; i < n; ++i)
        {
            pq.push({nums[i], i});
        }
        for (int i = 0; i < k; ++i)
        {
            auto [_, idx] = pq.top();
            pq.pop();
            // cout << idx << '\n';
            nums[idx] *= multiplier;
            pq.push({nums[idx], idx});
        }
        return nums;
    }
};
