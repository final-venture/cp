#define ll long long
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        ll n = gifts.size();
        priority_queue<ll> pq(gifts.begin(), gifts.end());
        for (ll i = 0; i < k; ++i)
        {
            ll x = pq.top();
            pq.pop();
            ll rem = sqrtl(x);
            pq.push(rem);
        }
        ll ret = 0;
        while (!pq.empty())
        {
            ll x = pq.top();
            pq.pop();
            ret += x;
        }
        return ret;
    }
};
