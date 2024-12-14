// moddiv Cheese Method
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define MOD 1000000007

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
    int n;
    cin >> n;
    ll maxx = (1 + n) * n / 2;
    // cout << maxx << '\n';
    if (maxx % 2)
    {
        cout << 0 << '\n';
        return;
    }
    vector<ll> dp(maxx / 2 + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= n; ++j)
    {
        // cout << i << '\n';
        for (int i = maxx / 2; i >= j; --i)
        {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
        // for (int x : dp) cout << x << ' ';
        // cout << '\n';
    }

    cout << dp[maxx / 2] * ((MOD + 1) / 2) % MOD << '\n';
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}

// moddiv Normal Method
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define MOD 1000000007
#define int ll

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int mod_exp(int base, int exp)
{
    int ret = 1;
    while (exp)
    {
        if (exp % 2)
        {
            ret = (ret * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return ret;
}

int divv(int a, int b)
{
    return a * mod_exp(b, MOD - 2) % MOD;
}

void solve()
{
    int n;
    cin >> n;
    ll maxx = (1 + n) * n / 2;
    // cout << maxx << '\n';
    if (maxx % 2)
    {
        cout << 0 << '\n';
        return;
    }
    vector<ll> dp(maxx / 2 + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= n; ++j)
    {
        // cout << i << '\n';
        for (int i = maxx / 2; i >= j; --i)
        {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
        // for (int x : dp) cout << x << ' ';
        // cout << '\n';
    }

    cout << divv(dp[maxx / 2], 2) << '\n';
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
