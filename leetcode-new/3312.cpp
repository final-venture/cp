#define ll long long
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxx = *max_element(nums.begin(), nums.end());
        vector<ll> freqs(maxx + 1, 0);
        for (int num : nums)
        {
            freqs[num]++;
        }

        vector<ll> cnt(maxx + 1, 0); // cnt[i] will store # of elements which are divisible by i.
        for (int i = 1; i <= maxx; ++i)
        {
            for (int j = i; j <= maxx; j += i)
            {
                cnt[i] += freqs[j];
            }
        }

        vector<ll> sieve(maxx + 1, 0); // sieve[i] will store # of pairs with gcd of i.
        for (int i = maxx; i >= 1; --i)
        {
            if (cnt[i] >= 2)
            {
                sieve[i] = cnt[i] * (cnt[i] - 1) / 2;
            }
            for (int j = 2 * i; j <= maxx; j += i)
            {
                sieve[i] -= sieve[j];
            }
        }

        vector<ll> pfx(maxx + 1, 0);
        for (int i = 1; i < maxx + 1; ++i)
        {
            pfx[i] = pfx[i - 1] + sieve[i];
        }

        vector<int> ret;
        for (ll q : queries)
        {
            ll l = 0, r = maxx;
            while (l < r)
            {
                ll m = l + (r - l) / 2;
                if (pfx[m] > q)
                {
                    r = m;
                }
                else
                {
                    l = m + 1;
                }
            }
            ret.push_back(l);
        }
        return ret;
    }
};
