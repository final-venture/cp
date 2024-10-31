class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int res = 0;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        int lvl = 0;
        q.push({beginWord, 1});
        while (!q.empty())
        {
            auto &xp = q.front();
            string &x = xp.first;
            int currlvl = xp.second;
            if (x == endWord)
            {
                res = currlvl;
                break;
            }
            wordSet.erase(x);
            for (int i = 0; i < x.size(); ++i)
            {
                string tmp = x;
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    tmp[i] = c;
                    if (wordSet.find(tmp) != wordSet.end())
                    {
                        q.push({tmp, currlvl + 1});
                    }
                }
            }
            q.pop();
        }
        return res;
    }
};
