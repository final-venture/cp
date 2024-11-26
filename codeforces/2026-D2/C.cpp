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
    int n;
    string s;
    cin >> n >> s;
    vector<int> zeroes {};
    vector<int> ones {};
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            zeroes.push_back(i + 1);
        }
        else
        {
            ones.push_back(i + 1);
        }
    }
    ll res = 0;
    while (!zeroes.empty() && !ones.empty())
    {
        if (ones.back() > zeroes.back())
        {
            res += zeroes.back();
            ones.pop_back();
            zeroes.pop_back();
        }
        else
        {
            res += zeroes.back();
            zeroes.pop_back();
        }
    }
    while (!zeroes.empty())
    {
        res += zeroes.back();
        zeroes.pop_back();
    }
    int l = 0, r = ones.size() - 1;
    while (l <= r)
    {
        res += ones[l];
        --r;
        ++l;
    }
    
    cout << res << '\n';
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
