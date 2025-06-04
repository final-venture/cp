class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> pfxz(n, 0);
        vector<int> sfxo(n, 0);
        for (int i = 0; i < n; ++i)
        {
            pfxz[i] = static_cast<int>((s[i] == '0'));
            if (i > 0) pfxz[i] += pfxz[i - 1];
        }
        for (int i = n - 1; i >= 0; --i)
        {
            sfxo[i] = static_cast<int>((s[i] == '1'));
            if (i < n - 1) sfxo[i] += sfxo[i + 1];
        }

        int maxx = 0;
        for (int i = 1; i < n; ++i)
        {
            maxx = max(maxx, pfxz[i - 1] + sfxo[i]);
        }
        return maxx;
    }
};