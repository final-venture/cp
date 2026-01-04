class Solution
{
private:
    bool check(vector<string> &vec)
    {
        string &top = vec[0];
        string &left = vec[1];
        string &right = vec[2];
        string &bottom = vec[3];
        return (top[0] == left[0] && top[3] == right[0] && bottom[0] == left[3] && bottom[3] == right[3]);
    }

public:
    vector<vector<string>> wordSquares(vector<string> &words)
    {
        vector<vector<string>> ret;
        int n = words.size();
        for (int a = 0; a < n; ++a)
        {
            for (int b = 0; b < n; ++b)
            {
                if (a == b)
                {
                    continue;
                }
                for (int c = 0; c < n; ++c)
                {
                    if (a == c || b == c)
                    {
                        continue;
                    }
                    for (int d = 0; d < n; ++d)
                    {
                        if (d == a || d == b || d == c)
                        {
                            continue;
                        }
                        vector<string> cand = {words[a], words[b], words[c], words[d]};
                        if (check(cand))
                        {
                            ret.push_back(cand);
                        }
                    }
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
