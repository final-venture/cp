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

vector<int> fct(200005);

// LEARN
int mod_exp(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int divv(int a, int b)
{
    return a * mod_exp(b, MOD - 2) % MOD;
}

int C(int n, int r)
{
    if (r == n) return 1;
    int nf = fct[n];
    int sf = fct[n - r];
    int df = fct[r];
    return divv(nf, (sf % MOD * df % MOD) % MOD) % MOD;
}

void solve()
{
    fct[0] = 1;
    for (int i = 1; i < 200002; ++i)
    {
        fct[i] = (fct[i - 1] * i) % MOD; // no need to mod fct[i - 1] because prev already modded
    }
    // for (int i = 0; i < 500; ++i)
    // {
    //     cout << fct[i] << ' ';
    // }
    // cout << '\n';
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pfxo(n, 0);
    vector<int> sfxe(n, 0);
    for (int i = 0; i < n; ++i)
    {
        pfxo[i] = (s[i] == '(');
        if (i > 0)
        {
            pfxo[i] += pfxo[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        sfxe[i] = (s[i] == ')');
        if (i < n - 1)
        {
            sfxe[i] += sfxe[i + 1];
        }
    }
    // for (int x : pfxo) cout << x << ' ';
    // cout << '\n';
    // for (int x : sfxe) cout << x << ' ';
    // cout << '\n';
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == ')') continue;
        int left = pfxo[i] - 1;
        int right = sfxe[i];
        int total = left + right;
        if (right <= 0) continue;
        // cout << total << ' ' << right - 1 << '\n';
        res += C(total, right - 1);
        res %= MOD;
    }
    cout << res << '\n';
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
