#define ll long long
class Solution {
public:
    ll gcd(ll x, ll y)
    {
        if (!y) return x;
        return gcd(y, x % y);
    }
    ll lcm(ll x, ll y)
    {
        return (x / gcd(x, y)) * y;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<ll> lcms {a, b, c, lcm(a, b), lcm(b, c), lcm(a, c), lcm(lcm(a, b), c)};
        ll l = 1; ll r = 2e9;
        while (l < r)
        {
            ll m = l + (r - l) / 2;
            ll cnt = 0;
            for (int i = 0; i <= 2; ++i)
            {
                cnt += (m / lcms[i]);
            }
            for (int i = 3; i <= 5; ++i)
            {
                cnt -= (m / lcms[i]);
            }
            cnt += (m / lcms[6]);
            if (cnt < n) l = m + 1;
            else r = m;
        }
        return l;
    }
};
