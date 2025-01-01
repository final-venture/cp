class Solution
{
private:
    unordered_map<string, int> w2l;
    vector<vector<string>> res;
    string beginWord;
    void dfs(string word, vector<string> &cand)
    {
        if (word == beginWord)
        {
            reverse(cand.begin(), cand.end());
            res.push_back(cand);
            reverse(cand.begin(), cand.end());
            return;
        }
        int steps = w2l[word];
        for (int i = 0; i < word.size(); ++i)
        {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; ++c)
            {
                word[i] = c;
                if (w2l[word] == steps - 1)
                {
                    cand.push_back(word);
                    dfs(word, cand);
                    cand.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        this->beginWord = beginWord;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        w2l[beginWord] = 1;
        wordSet.erase(beginWord);

        while (!q.empty())
        {
            string word = q.front();
            int lvl = w2l[word];
            q.pop();
            if (word == endWord)
                break;
            for (int i = 0; i < word.size(); ++i)
            {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    word[i] = c;
                    if (wordSet.find(word) != wordSet.end())
                    {
                        q.push(word);
                        wordSet.erase(word);
                        w2l[word] = lvl + 1;
                    }
                }
                word[i] = original;
            }
        }

        vector<string> cand{endWord};
        if (w2l.find(endWord) != w2l.end())
        {
            dfs(endWord, cand);
            return res;
        }
        return {};
    }
};
