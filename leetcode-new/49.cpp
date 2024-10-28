class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res{};
        unordered_map<string, vector<string>> s2c{};
        for (string &str : strs)
        {
            string sstr{str};
            sort(sstr.begin(), sstr.end());
            s2c[sstr].push_back(str);
        }
        for (auto &v : s2c)
        {
            res.push_back(v.second);
        }
        return res;
    }
};
