class Solution
{
public:
    int C2I(char c)
    {
        return c - 'a';
    }
    vector<int> char_cnt;
    vector<string> words;
    vector<char> letters;
    vector<int> score;

    int dfs(int idx)
    {
        if (idx >= words.size())
        {
            return 0;
        }

        int notTake = dfs(idx + 1);

        int take = 0;
        int ok = 1;
        int cand_score = 0;
        for (char c : words[idx])
        {
            cand_score += score[C2I(c)];
            if (--char_cnt[C2I(c)] < 0)
            {
                ok = 0;
            }
        }

        if (ok)
        {
            take = cand_score + dfs(idx + 1);
        }
        for (char c : words[idx])
        {
            ++char_cnt[C2I(c)];
        }

        return max(take, notTake);
    }

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        this->words = words;
        this->letters = letters;
        this->score = score;
        char_cnt.resize(26, 0);
        for (char c : letters)
        {
            ++char_cnt[C2I(c)];
        }
        return dfs(0);
    }
};
