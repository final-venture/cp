class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int x) {
        int k = s.size() / x;
        unordered_map<string, int> s2c;
        for (int i = 0; i < t.size(); i += k)
        {
            s2c[t.substr(i, k)]++;
        }
        for (int i = 0; i < s.size(); i += k)
        {
            string cand = s.substr(i, k);
            if (!s2c[cand])
                return false;
            s2c[cand]--;
        }
        return true;
    }
};
