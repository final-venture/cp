#define dbl double
#define EPS 1e-6
class Solution {
public:
    int n;
    dbl logTarget;
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        this -> n = nums.size();
        logTarget = log(target);
        return dfs(0, 0, 0, nums);
    }
private:
    bool dfs(int i, dbl cnt1, dbl cnt2, vector<int>& nums)
    {
        if (i == n)
        {
            if ((abs(cnt1 - logTarget) < EPS) && (abs(cnt2 - logTarget) < EPS))
            {
                return true;
            }
            return false;
        }
        bool take = dfs(i + 1, cnt1 + log(nums[i]), cnt2, nums);
        bool notTake = dfs(i + 1, cnt1, cnt2 + log(nums[i]), nums);
        return (take || notTake);
    }
};
