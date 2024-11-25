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
    vector<int> res(n, -1);
    if (n % 2 && n < 27)
    {
        cout << -1 << '\n';
        return;
    }
    if (n % 2)
    {
        res[0] = 1;
        res[9] = 1;
        res[25] = 1;
        res[22] = 2;
        res[26] = 2;
        int curridx = 1;
        int currnum = 3;
        int cnt = 0;
        while (curridx < n)
        {
            if (cnt == 2)
            {
                cnt = 0;
                ++currnum;
            }
            if (res[curridx] != -1)
            {
                ++curridx;
            }
            else
            {
                res[curridx] = currnum;
                ++curridx;
                ++cnt;
            }
        }
        for (int x : res) cout << x << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n / 2; ++i)
    {
        cout << i << ' ' << i << ' ';
    }
    cout << '\n';
}

// void solve2()
// {
//     unordered_set<int> pfct;
//     vector<vector<int>> res;
//     for (int i = 1; i < 51; ++i)
//     {
//         pfct.insert(i * i);
//     }
//     for (int i = 1; i < 26; ++i)
//     {
//         for (int j = 1; j < 26; ++j)
//         {
//             int cand = i * i + j * j;
//             if (pfct.find(cand) != pfct.end())
//             {
//                 res.push_back({cand, i, j});
//             }
//         }
//     }
//     sort(all(res));
//     for (auto& x : res)
//     {
//         cout << x[1] << ' ' << x[2] << ' ' << x[0] << '\n';
//     }
// }

int main()
{
    init();
    // solve2();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
