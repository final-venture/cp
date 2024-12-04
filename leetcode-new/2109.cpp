class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        int n = s.size();
        int space[300005];
        memset(space, 0, sizeof(space));
        for (int s : spaces)
        {
            space[s] = 1;
        }
        stringstream res;
        while (i < n)
        {
            if (space[i]) res << ' ';
            res << s[i];
            ++i;
        }
        return res.str();
    }
};
