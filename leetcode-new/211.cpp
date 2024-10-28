class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEnd;
    TrieNode() : children{}, isEnd{false} {}
};

class WordDictionary
{
private:
    TrieNode *head;

public:
    WordDictionary()
    {
        head = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *curr = head;
        for (char c : word)
        {
            auto &wl = curr->children;
            if (wl.find(c) == wl.end())
                wl[c] = new TrieNode();
            curr = wl[c];
        }
        curr->isEnd = true;
    }

    bool search(string word)
    {
        return helper(word, 0, head);
    }

private:
    bool helper(string &word, int idx, TrieNode *curr)
    {
        if (idx == word.length())
            return curr->isEnd;
        char c = word[idx];
        auto &wl = curr->children;
        if (c == '.')
        {
            for (auto &pair : wl)
            {
                if (helper(word, idx + 1, pair.second))
                    return true;
            }
            return false;
        }
        else
        {
            if (wl.find(c) == wl.end())
                return false;
            return helper(word, idx + 1, wl[c]);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
