class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEnd;
    TrieNode() : children{}, isEnd{false} {}

    void add(string word)
    {
        TrieNode *curr = this;
        for (char c : word)
        {
            auto &wl = curr->children;
            if (wl.find(c) == wl.end())
                wl[c] = new TrieNode();
            curr = wl[c];
        }
        curr->isEnd = true;
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        this->board = board;
        r = board.size();
        c = board[0].size();
        for (auto word : words)
            root->add(word);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                helper(i, j, root, "");
            }
        }
        return res;
    }

private:
    vector<vector<char>> board;
    vector<string> res{};
    int r, c;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void helper(int cr, int cc, TrieNode *node, string word)
    {
        if (cr < 0 || cr >= r || cc < 0 || cc >= c || board[cr][cc] == '#' || node->children.find(board[cr][cc]) == node->children.end())
            return;

        char c = board[cr][cc];
        board[cr][cc] = '#';
        node = node->children[c];
        word += c;
        if (node->isEnd)
        {
            node->isEnd = false;
            res.push_back(word);
        }

        for (const auto &[dx, dy] : dirs)
        {
            helper(cr + dx, cc + dy, node, word);
        }
        board[cr][cc] = c;
    }
};
