#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)

void init()
{
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    ll a, b, k;
    cin >> a >> b >> k;
    if (b < a) swap(a, b);
    pair<ll, ll> best {k, b};
    for (int i = 0; i < b; ++i)
    {
        ll low = max(0ll, (k - i * a) / b);
        ll high = low + 1;
        best = min(best, {abs(k - i * a - low * b), i + low});
        best = min(best, {abs(k - i * a - high * b), i + high});
    }
    cout << best.first << " " << best.second << '\n';
}

int main()
{
    init();
    solve();
    return 0;
}
