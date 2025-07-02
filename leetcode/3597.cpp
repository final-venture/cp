class Solution
{
public:
    vector<string> partitionString(string s)
    {
        int n = s.size();
        vector<string> ret;
        unordered_set<string> seen;
        string cand;
        for (int i = 0; i < n; ++i)
        {
            cand.push_back(s[i]);
            if (!cand.empty() && seen.find(cand) == seen.end())
            {
                ret.push_back(cand);
                seen.insert(cand);
                cand = "";
            }
        }
        return ret;
    }
};