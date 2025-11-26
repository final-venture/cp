// USE FENWICK TREE TO STORE COUNTS OF ELEMENTS IN PFX.
// "COORDINATE COMPRESS" USING AN OFFSET.

class Solution
{
public:
    vector<long long> fenw;
    vector<int> arr;
    int sz;
    void update(int index, int delta)
    {
        while (index < sz)
        {
            fenw[index] += delta;
            index += (index & -index);
        }
    }

    long long sumRange(int left, int right)
    {
        long long rightSum = 0, leftSum = 0;
        while (right > 0)
        {
            rightSum += fenw[right];
            right -= (right & -right);
        }
        while (left > 0)
        {
            leftSum += fenw[left];
            left -= (left & -left);
        }
        return rightSum - leftSum;
    }

    long long countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size();
        arr = nums;
        arr.insert(arr.begin(), 0);
        fenw.resize(2 * n + 10, 0);
        sz = fenw.size();
        int offset = n + 5;
        long long ret = 0;
        int curr_pfx = 0;
        update(curr_pfx + offset, 1);

        for (int i = 1; i <= n; ++i)
        {
            if (arr[i] == target)
            {
                ++curr_pfx;
            }
            else
            {
                --curr_pfx;
            }
            ret += sumRange(0, curr_pfx + offset - 1);
            update(curr_pfx + offset, 1);
        }

        return ret;
    }
};
