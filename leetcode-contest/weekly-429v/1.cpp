class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> cand(nums.begin(), nums.end());
        unordered_set<int> candSet(nums.begin(), nums.end());
        int cnt = 0;
        while (cand.size() != candSet.size())
        {
            ++cnt;
            cand.clear();
            for (int i = cnt * 3; i < nums.size(); ++i)
            {
                cand.push_back(nums[i]);
            }
            candSet = unordered_set<int>(cand.begin(), cand.end());
            // for (int x : cand) cout << x << ' ';
            // cout << '\n';
            // for (int x : candSet) cout << x << ' ';
            // cout << '\n';
            // cout << cand.size() << ' ' << candSet.size();
        }
        return cnt;
    }
};
