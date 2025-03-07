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
    cin >> n;
    vector<int> res(n);
    vector<int> seen(102, 0);
    int cit = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = cit; j < 101; ++j)
        {
            if (seen[j % (i + 1)]) continue;
            res[i] = j;
            seen[j % (i + 1)] = 1;
            cit = j + 1;
            break;
        }
    }
    for (int x : res) cout << x << ' ';
    cout << '\n';
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
