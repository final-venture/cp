class UF
{
private:
    vector<int> par;
    vector<int> rank;
public:
    UF(int n)
    {
        par.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
    }
    int find(int x)
    {
        int p = par[x];
        while (p != par[p])
        {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    void unionn(int x1, int x2)
    {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2) return;
        if (p1 > p2)
        {
            par[p1] = par[p2];
        }
        else if (p1 < p2)
        {
            par[p2] = par[p1];
        }
        // else
        // {
        //     par[p1] = par[p2];
        // }
    }
};

class Solution {
private:
    int c2n(char c) 
    {
        return c - 'a';
    }

    char n2c(int index) 
    {
        return static_cast<char>('a' + index);
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UF uf(26);
        int n = s1.size(), nn = baseStr.size();
        for (int i = 0; i < n; ++i)
        {
            int a = c2n(s1[i]), b = c2n(s2[i]);
            uf.unionn(a, b);
        }
        string ret;
        for (int i = 0; i < nn; ++i)
        {
            ret.push_back(n2c(uf.find(c2n(baseStr[i]))));
        }
        return ret;
    }
};
