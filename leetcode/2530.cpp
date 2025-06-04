class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long long res = 0;
        priority_queue<int> pq;
        for (long long num : nums)
        {
            pq.push(num);
        }
        for (int i = 0; i < k; i++)
        {
            long long tmp = pq.top();
            res += tmp;
            pq.pop();
            pq.push(ceil((double)tmp / 3));
        }
        return res;
    }
};
