class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string_view> wordSet(wordDict.begin(), wordDict.end());
        string_view sv(s);
        int n = s.size();
        unordered_set<int> dp{n};

        for (int i = n - 1; i >= 0; --i)
        {
            for (int endp : dp)
            {
                int substrl = endp - i;
                if (wordSet.find(sv.substr(i, substrl)) != wordSet.end())
                {
                    dp.insert(i);
                }
            }
        }
        return (dp.find(0) != dp.end());
    }
};
