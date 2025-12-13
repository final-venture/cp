class Solution
{
public:
    vector<int> decode(vector<int> &encoded)
    {
        int n = encoded.size();
        vector<int> skipcoded(n + 1);
        for (int i = 1; i < n; ++i)
        {
            skipcoded[i] = encoded[i - 1] ^ encoded[i];
        }
        // skipcoded[i] = perm[i] ^ perm[i + 2] (so we skip i + 1)
        // encoded[i] = perm[i] ^ perm[i + 1]
        int allXor = 0;
        for (int i = 1; i <= n + 1; ++i)
        {
            allXor ^= i;
        }

        // for odd ret[i], we dont need to use skipcoded
        // for even, we do.

        // ret[0] = allXor ^ encoded[1] ^ encoded[3] ^ encoded[5] ^ ...
        // ret[2] = allXor ^ encoded[0] ^ encoded[3] ^ encoded[5] ^ ...
        // ret[4] = allXor ^ encoded[0] ^ encoded[2] ^ encoded[5] ^ ...

        // ret[1] = allXor ^ skipcoded[1] ^ encoded[3] ^ encoded[5] ^ ...
        // ret[3] = allXor ^ encoded[0] ^ skipcoded[3] ^ encoded[5] ^ ...
        // ret[5] = allXor ^ encoded[0] ^ encoded[2] ^ skipcoded[5] ^ encoded[7] ^ ...

        vector<int> pfx(n + 1, 0);
        for (int i = 1; i <= n; i += 2)
        {
            pfx[i] = pfx[max(0, i - 2)] ^ encoded[i - 1];
        }
        for (int i = 2; i <= n; i += 2)
        {
            pfx[i] = pfx[i - 2] ^ encoded[i - 1];
        }

        // for (auto x : pfx) cout << x << ' ';

        vector<int> ret(n + 1);
        for (int i = 0; i <= n; i += 2)
        {
            ret[i] = allXor ^ pfx[max(0, i - 1)] ^ pfx[i] ^ pfx[n];
        }
        for (int i = 1; i <= n; i += 2)
        {
            ret[i] = allXor ^ pfx[max(0, i - 2)] ^ skipcoded[i] ^ pfx[i + 1] ^ pfx[n];
        }
        return ret;
    }
};
