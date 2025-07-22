class Solution {
private:
    void construct(vector<int>& sieve)
    {
        int n = sieve.size();
        sieve[0] = 0;
        sieve[1] = 0;
        for (int i = 2; i * i < n; ++i)
        {

            for (int j = 2 * i; j < n; j += i)
            {
                sieve[j] = 0;
            }
        }
    }
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum_a = 0, sum_b = 0;
        vector<int> sieve(n + 1, 1);
        construct(sieve);
        for (int i = 0; i < n; ++i)
        {
            if (sieve[i])
            {
                sum_a += nums[i];
            }
            else
            {
                sum_b += nums[i];
            }
        }
        return abs(sum_a - sum_b);
    }
};
