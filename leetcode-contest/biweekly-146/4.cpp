#define ll long long
#define MOD 1000000007
class Solution {
private:
    vector<ll> fct(1009);
public:
    ll divv(ll a, ll b)
    {
        return a * mod_exp(b, MOD - 2) % MOD;
    }
    ll C(ll n, ll r)
    {
        if (r > n) return 0;
        if (r == n) return 1;
        ll nf = fct[n];
        ll sf = fct[n - r];
        ll df = fct[r];
        return divv(nf, (sf % MOD * df % MOD) % MOD) % MOD;
    }
    ll mod_exp(ll base, ll exp)
    {
        ll result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
    int subsequencesWithMiddleMode(vector<int>& nums) {
        fct[0] = 1;
        for (int i = 1; i < 1009; ++i)
        {
            fct[i] = (fct[i - 1] * i) % MOD;
        }
        int n = nums.size();
        unordered_map<int, int> freq_left;
        ++freq_left[nums[0]]; ++freq_left[nums[1]];
        unordered_map<int, int> freq_right;
        for (int i = 3; i < n; ++i)
        {
            ++freq_right[nums[i]];
        }
        for (int i = 2; i < n - 2; ++i)
        {
            for (int qty = 2; qty <= 5; ++qty)
            {
                for (int l = 0; l < i; ++l)
                {

                }
            }
        }
    }
};
