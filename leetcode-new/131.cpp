class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> cand;
        dfs(res, s, cand, 0);
        return res;
    }

    bool isPalindrome(string str)
    {
        int l = 0;
        int r = str.length() - 1;
        while (l < r)
        {
            if (str[l] != str[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void dfs(vector<vector<string>> &res, const string &s, vector<string> &cand, int i)
    {
        if (i == s.length())
        {
            res.push_back(cand);
            return;
        }
        for (int j = i + 1; j <= s.length(); j++)
        {
            string neww = s.substr(i, j - i);
            if (isPalindrome(neww))
            {
                cand.push_back(neww);
                dfs(res, s, cand, j);
                cand.pop_back();
            }
        }
    }
};
