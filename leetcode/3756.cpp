class Solution
{
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> pfx(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            pfx[i] = pfx[i - 1] + (s[i - 1] - '0');
        }
        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        vector<int> nzCount(n + 1, 0); // non zero count
        vector<long long> modX(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            int digit = s[i - 1] - '0';
            nzCount[i] = nzCount[i - 1];
            modX[i] = modX[i - 1];

            if (digit != 0)
            {
                nzCount[i]++;
                modX[i] *= 10;
                modX[i] += digit;
                modX[i] %= MOD;
            }
        }

        // for (auto x : nzCount) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        // for (auto x : modX) {
        //     cout << x << ' ';
        // }
        // cout << '\n';

        vector<int> ret;
        for (auto &q : queries)
        {
            int st = q[0], ed = q[1];
            ++st;
            ++ed;
            int nonZeros = nzCount[ed] - nzCount[st - 1];
            // cout << nzCount[ed] << ' ' << nzCount[st - 1] << '\n';
            // cout << nonZeros << '\n';
            // cout << modX[st - 1] * pow10[nonZeros] << '\n';
            long long x = (modX[ed] - (modX[st - 1] * pow10[nonZeros]) % MOD + MOD) % MOD;
            long long sum = pfx[ed] - pfx[st - 1];
            // cout << "x: " << x << ' ' << "sum: " << sum << '\n';

            long long cand = (x * sum) % MOD;
            ret.push_back(cand);
        }
        return ret;
    }
};
