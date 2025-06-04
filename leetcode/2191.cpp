class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i)
        {
            string s = to_string(nums[i]);
            for (char &c : s)
            {
                c = mapping[c - '0'] + '0';
            }
            arr[i] = {stoi(s), i};
        }
        sort(arr.begin(), arr.end());
        vector<int> ret(n);
        for (int i = 0; i < n; ++i)
        {
            ret[i] = nums[arr[i].second];
        }
        return ret;
    }
};
