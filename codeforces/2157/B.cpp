#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

int n, x, y, sz;
string s;
vector<int> cnts;

bool valid(int r, int c)
{
    return (abs(r) <= sz && abs(c) <= sz && abs(r) + abs(c) <= sz + cnts[1]);
}

void solve()
{
    cin >> n >> x >> y;
    cin >> s;
    sz = s.size();
    cnts.assign(2, 0); // cnts[0] is count of '4', cnts[1] is count of '8'
    for (int i = 0; i < sz; ++i)
    {
        if (s[i] == '4')
        {
            ++cnts[0];
        }
        else
        {
            ++cnts[1];
        }
    }
    string ret = (valid(x, y)) ? "YES" : "NO";
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
