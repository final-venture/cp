class Solution {
private:
    int n;
    string s;
    unordered_map<string, int> mpp;
public:
    bool check(string& x)
    {
        int nn = x.size();
        for (int i = 0; i + 1 < nn; ++i)
        {
            if (x[i] != x[i + 1]) return false;
        }
        return true;
    }

    void dfs(int i, int j)
    {
        if (j >= n || i >= n) return;
        int sz = j - i + 1;
        string x = s.substr(i, sz);
        if (check(x)) ++mpp[x];
    }

    int maximumLength(string s) {
        n = s.size();
        this -> s = s;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                dfs(i, j);
            }
        }
        int ret = -1;
        for (auto& [s, c] : mpp)
        {
            int nnn = s.size();
            if (c >= 3 && nnn > ret)
            {
                ret = nnn;
            }
        }
        return ret;
    }
};
