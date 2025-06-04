// Solution from codingMohan: https://www.youtube.com/watch?v=0ErpIxK9QUI

const int N = 5e4 + 1;
const int P = 31;
const int M = 1e9 + 9;

const int INF = 1e9;

#define F first
#define S second

int dp[N];

typedef long long int ll;

class Solution
{
    vector<ll> p_pow;
    vector<ll> inv_p_pow;

    string s;
    int s_len;
    vector<ll> s_hash;

    vector<int> uniq_word_lengths;
    unordered_map<int, int> cost_per_str;

    // a^b % M
    ll FastPower(ll a, ll b)
    {
        ll ans = 1;
        while (b)
        {
            if (b & 1)
                ans = (ans * a) % M;
            a = (a * a) % M;
            b /= 2;
        }
        return ans;
    }

    void ComputePower()
    {
        if (!p_pow.empty())
            return;

        p_pow.resize(N, 1);
        for (int i = 1; i < N; i++)
            p_pow[i] = (p_pow[i - 1] * P) % M;

        inv_p_pow.resize(N, 1);

        inv_p_pow[N - 1] = FastPower(p_pow[N - 1], M - 2);
        for (int i = N - 2; i > 0; i--)
            inv_p_pow[i] = (inv_p_pow[i + 1] * P) % M;
    }

    vector<ll> HashIt(const string &s)
    {
        int S = s.size();
        vector<ll> prefix_hash(S + 1, 0);

        for (int i = 1; i <= S; i++)
        {
            ll cur = (p_pow[i] * (s[i - 1] - 'a' + 1)) % M;
            prefix_hash[i] = (prefix_hash[i - 1] + cur) % M;
        }
        return prefix_hash;
    }

    inline ll HashOfRange(int l, int r)
    {
        if (r > s_len)
            return -1;

        ll hash = (s_hash[r] - s_hash[l - 1] + M) % M;
        return (hash * inv_p_pow[l - 1]) % M;
    }

    int MinCost(int ind)
    {
        if (ind == s_len)
            return 0;

        int &ans = dp[ind];
        if (ans != -1)
            return ans;
        ans = INF;

        for (int &len : uniq_word_lengths)
        {
            int hash = HashOfRange(ind + 1, ind + len);

            auto it = cost_per_str.find(hash);
            if (it == cost_per_str.end())
                continue;

            ans = min(ans, it->S + MinCost(ind + len));
        }
        return ans;
    }

public:
    int minimumCost(string target, vector<string> &words, vector<int> &costs)
    {
        uniq_word_lengths.clear(), cost_per_str.clear();
        memset(dp, -1, sizeof(dp));
        ComputePower();

        s = target, s_len = s.length();
        s_hash = HashIt(target);

        unordered_set<int> word_lens;
        for (auto &w : words)
        {
            word_lens.insert(w.length());
        }
        uniq_word_lengths.assign(word_lens.begin(), word_lens.end());

        for (int i = 0; i < words.size(); i++)
        {
            int len = words[i].length();
            ll hash = HashIt(words[i]).back();

            auto it = cost_per_str.find(hash);
            if (it == cost_per_str.end())
                cost_per_str[hash] = costs[i];
            else
                it->S = min(it->S, costs[i]);
        }

        int ans = MinCost(0);
        if (ans == INF)
            ans = -1;
        return ans;
    }
};
