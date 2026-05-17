#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define int ll
#define MOD 1000000007

// #define LOCAL

void init()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    // OFF BY ONE TC SOLUTION - OVERFLOW?? MOD?? IDK
    int n, q;
    cin >> n >> q;
    vector<int> h(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
    sort(all(h), greater<void>());
    h.pb(0);
    vector<int> a(n + 2, 0);
    vector<int> b(n + 2, 0);
    for (int i = 1; i < n + 1; ++i)
    {
        a[i] = a[i - 1] + i * (h[i - 1] - h[i]);
        b[i] = ((b[i - 1] % MOD) + (i * (h[i - 1] * (h[i - 1] + 1) - h[i] * (h[i] + 1)) / 2) % MOD) % MOD;
    }

    // for (int i = 0; i < n + 1; ++i)
    // {
    //     cout << h[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i < n + 2; ++i)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i < n + 2; ++i)
    // {
    //     cout << b[i] << ' ';
    // }
    // cout << endl;

    while (q--)
    {
        int t;
        cin >> t;
        if (t > a[n])
        {
            cout << b[n] % MOD << '\n';
            continue;
        }
        int l = 0, r = n, res = n;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (a[m] <= t)
            {
                res = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        // cout << res << ' ' << a[res] << '\n';
        int remain = t - a[res]; // remaining throws
        int qty = res + 1; // qty pinecones
        int q1 = b[res] % MOD;
        int curr_h = h[res];
        int new_h = curr_h - remain / qty;
        int q2 = (qty * ((curr_h * (curr_h + 1) - new_h * (new_h + 1)) / 2) % MOD) % MOD;
        int remain2 = remain % qty;
        int q3 = (new_h * remain2) % MOD;
        cout << ((q1 + q2) % MOD + q3) % MOD << '\n';
    }
}

signed main()
{
    init();
#ifdef LOCAL
    int t;
    cin >> t;
    while (t--)
#endif
        solve();
    return 0;
}