#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    ll cards[n];
    for (ll i = 0; i < n; ++i)
    {
        cin >> cards[i];
    }
    ll sum = accumulate(cards, cards + n, 0ll);
    ll maxx = *max_element(cards, cards + n);
    ll maxpiles = 1;
    for (ll i = 2; i <= n; ++i)
    {
        ll targ = i * maxx;
        if (sum <= targ)
        {
            if (k < targ - sum) break;
            maxpiles = i;
        }
        if (sum > targ)
        {
            ll targ1 = (sum / i + 1) * i;
            if (k >= targ1 - sum || !(sum % i))
                maxpiles = i;
        }
    }
    cout << maxpiles << '\n';
}

void solve2()
{

}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
