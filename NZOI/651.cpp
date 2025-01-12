#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

ll n;
int k, q;

ll H(ll x)
{
    ll p = 1;
    int ret = 0;
    while (x > p)
    {
        x -= p;
        p *= k;
        ret += 1;
    }
    return ret;
}

vector<ll> A(ll x)
{
    vector<ll> ret;
    ll p = 1;
    ll s = 0;
    while (x > p)
    {
        x -= p;
        s += p;
        p *= k;
    }
    while (p > 1)
    {
        // x = 8, s = 3, p = 1
        // cout << x << ' ' << p << ' ' << s << '\n';
        ret.push_back(s + x);
        x -= 1;
        x /= k;
        x += 1;
        p /= k;
        s -= p;
    }
    ret.push_back(1);
    reverse(ret.begin(), ret.end());
    return ret;
}

ll LCA(ll a, ll b)
{
    vector<ll> anc_a = A(a);
    // for (int x : anc_a) cout << x << ' ';
    // cout << '\n';
    vector<ll> anc_b = A(b);
    // for (int x : anc_b) cout << x << ' ';
    // cout << '\n';
    while (anc_a.back() != anc_b.back())
    {
        if (anc_a < anc_b)
        {
            anc_b.pop_back();
        }
        else
        {
            anc_a.pop_back();
        }
    }
    return anc_a.back();
}

void solve()
{
    cin >> n;
    cin >> k >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (k == 1)
        {
            cout << abs(b - a) << '\n';
            continue;
        }
        cout << H(a) + H(b) - 2 * H(LCA(a, b)) << '\n';
    }
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
