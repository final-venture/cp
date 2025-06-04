class Solution
{
public:
    int n, nn;
    vector<vector<int>> adj;
    unordered_map<char, int> c2i;
    vector<int> i2ri;
    vector<int> seen;
    bool dfs(int node, int banned)
    {
        if (1 & (banned >> node))
            return 1;
        if (seen[node] == 1)
            return 0;
        seen[node] = 1;
        for (int nei : adj[node])
        {
            if (!dfs(nei, banned))
                return 0;
        }
        seen[node] = 2;
        return 1;
    }

    bool check(int banned)
    {
        seen.assign(nn, 0);
        for (int i = 0; i < nn; ++i)
        {
            if (seen[i])
                continue;
            if (!dfs(i, banned))
                return 0;
        }
        return 1;
    }

    vector<int> getCand(int mask)
    {
        vector<int> cand(26, 0);
        for (int i = 0; i < nn; ++i)
        {
            if (1 & (mask >> i))
            {
                ++cand[i2ri[i]];
            }
            ++cand[i2ri[i]];
        }
        return cand;
    }

    vector<vector<int>> supersequences(vector<string> &words)
    {
        n = words.size();
        for (string &word : words)
        {
            for (char &c : word)
            {
                if (c2i.find(c) != c2i.end())
                {
                    continue;
                }
                c2i[c] = c2i.size();
                i2ri.push_back(c - 'a');
            }
        }

        nn = c2i.size();
        adj.resize(nn);

        for (string &word : words)
        {
            adj[c2i[word[0]]].push_back(c2i[word[1]]);
        }

        int best = n;
        vector<vector<int>> ret;
        for (int i = 0; i < (1 << nn); ++i)
        {
            if (!check(i))
            {
                // cout << "i.lost" << '\n';
                continue;
            }
            int dblcnt = __builtin_popcount(i);
            if (dblcnt == best)
            {
                vector<int> x = getCand(i);
                ret.push_back(x);
            }
            else if (dblcnt < best)
            {
                best = dblcnt;
                ret.clear();
                vector<int> x = getCand(i);
                ret.push_back(x);
            }
        }
        return ret;
    }
};
