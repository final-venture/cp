class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string encoded;
        for (string &x : strs)
        {
            int n = x.length();
            encoded += ("#" + to_string(n) + "#" + x);
        }
        return encoded;
    }

    vector<string> decode(string s)
    {
        vector<string> decoded;
        int i = 0;
        while (i < s.length())
        {
            int j = i;
            while (s[++j] != '#')
                ;
            int numl = j - i - 1;
            int n = stoi(s.substr(i + 1, j - i - 1));
            decoded.push_back(s.substr(i + numl + 2, n));
            i += n + numl + 2;
        }
        return decoded;
    }
};
