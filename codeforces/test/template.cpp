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
    vector<int> accumz {};
    deque<int> accumo {};
    int res = 0;
    for (int i = n - 1; i >= 0; ++i)
    {
        while (s[i] == '1' && !accumz.empty())
        {  
            if (accumo.empty())
            {
                res += accumz.back();
                accumz.pop_back();
            }
            else
            {
                res += accumz.back();
                accumo.pop_front();
                accumz.pop_back();
            }
        }
        if (s[i] == '1')
        {
            accumo.push_front(i);
        }
        else if (s[i] == '0')
        {
            accumz.pb(i);
        }
    }
    while (!accumz.empty() && !accumo.empty())
    {
        res += accumz.back();
        accumo.pop_front();
        accumz.pop_back();
    }
    while (!accumz.empty())
    {
        res += accumz.back();
        accumz.pop_back();
    }
    while (!accumo.empty())
    {
        int f = accumo.front();
        int b = accumo.back();
        if (f != b)
        {
            res += b;
            accumo.pop_back();
            accumo.pop_front();
        }
        else
        {
            res += b;
            accumo.pop_back();
        }
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
