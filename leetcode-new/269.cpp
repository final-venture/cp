class Solution
{
public:
    string foreignDictionary(vector<string> &words)
    {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        int n = words.size();
        for (string &w : words)
        {
            for (char c : w)
            {
                adj[c] = {};
                indegree[c] = 0;
            }
        }
        for (int i = 0; i < n - 1; ++i)
        {
            string &w1 = words[i];
            string &w2 = words[i + 1];
            int minl = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0, minl) == w2.substr(0, minl))
            {
                return "";
            }
            for (int j = 0; j < minl; ++j)
            {
                if (w1[j] != w2[j])
                {
                    if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end())
                    {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for (auto &[c, deg] : indegree)
        {
            if (deg == 0)
            {
                q.push(c);
            }
        }

        string res;
        while (!q.empty())
        {
            char x = q.front();
            q.pop();
            res += x;
            for (char nei : adj[x])
            {
                --indegree[nei];
                if (indegree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }

        return (indegree.size() == res.size()) ? res : "";
    }
};
