class Solution {
private:
    int n;
    int numOps;
    vector<int> runs;
public:
    bool check(int x)
    {
        int curr = 0;
        for (int r : runs)
        {
            curr += r / (x + 1);
            if (curr > numOps) return false;
        }
        return true;
    }
    int minLength(string s, int numOps) {
        this -> numOps = numOps;
        n = s.size();
        int edgeOps = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((s[i] - '0') == (i & 1))
            {
                ++edgeOps;
            }
        }
        if (min(n - edgeOps, edgeOps) <= numOps) return 1;
        runs.push_back(1);
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == s[i - 1])
            {
                ++runs.back();
            }
            else
            {
                runs.push_back(1);
            }
        }
        int l = 2, r = n;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (check(m))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
};
