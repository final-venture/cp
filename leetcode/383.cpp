class Solution
{
public:
    bool canConstruct(string ra, string ma)
    {
        int n = ra.size(), m = ma.size();
        vector<int> cnt(28, 0);
        for (int i = 0; i < n; ++i)
        {
            cnt[ra[i] - 'a']++;
        }
        for (int i = 0; i < m; ++i)
        {
            cnt[ma[i] - 'a']--;
        }
        return all_of(cnt.begin(), cnt.end(), [](int x)
                      { return x <= 0; });
    }
};
