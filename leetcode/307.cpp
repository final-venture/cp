// segment tree
class NumArray
{
private:
    vector<int> nums;
    vector<int> seg;
    int n;

public:
    NumArray(vector<int> &nums)
    {
        this->n = nums.size();
        seg.resize(4 * n + 4);
        this->nums = nums;
        build(1, 0, n - 1);
    }

    void build(int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = nums[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(idx * 2, l, m);
        build(idx * 2 + 1, m + 1, r);
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }

    int queryy(int idx, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }
        if (qr < l || r < ql)
        {
            return 0;
        }
        int m = l + (r - l) / 2;
        int left = queryy(idx * 2, l, m, ql, qr);
        int right = queryy(idx * 2 + 1, m + 1, r, ql, qr);
        return left + right;
    }

    int updatee(int idx, int l, int r, int t, int v)
    {
        if (l == r && r == t)
        {
            nums[l] = v;
            seg[idx] = v;
            return seg[idx];
        }
        if (l > t || r < t)
        {
            return seg[idx];
        }
        int m = l + (r - l) / 2;
        int left = updatee(idx * 2, l, m, t, v);
        int right = updatee(idx * 2 + 1, m + 1, r, t, v);
        return seg[idx] = left + right;
    }

    void update(int index, int val)
    {
        updatee(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return queryy(1, 0, n - 1, left, right);
    }
};

// fenwick tree
class NumArray
{
private:
    vector<int> nums;
    vector<int> fenw;
    int n;

public:
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        this->n = nums.size();
        fenw.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            fenw[i] += nums[i - 1];
            int parent = i + (i & -i);
            if (parent <= n)
            {
                fenw[parent] += fenw[i];
            }
        }
    }

    void update(int index, int val)
    {
        ++index;
        int delta = val - nums[index - 1];
        nums[index - 1] = val;
        while (index <= n)
        {
            fenw[index] += delta;
            index += (index & -index);
        }
    }

    int sumRange(int left, int right)
    {
        ++right;
        int rightSum = 0, leftSum = 0;
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
};
