class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int ret = 0;
        int n = derived.size();
        for (int i = 0; i < n; ++i)
        {
            ret ^= derived[i];
        }
        return (ret == 0);
    }
};