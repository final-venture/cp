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
    vector<vector<ll>> vec(n, vector<ll>(4));
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i][2] >> vec[i][3];
        vec[i][0] = min(vec[i][2], vec[i][3]);
        vec[i][1] = max(vec[i][2], vec[i][3]);
    }
    sort(all(vec));
    for (auto& x : vec)
    {
        cout << x[2] << ' ' << x[3] << ' ';
    }
    cout << '\n';
}

// void solve2()
// {
//     int res1 = 0;
//     int res2 = 0;
//     vector<int> arr1 = {4, 1, 2, 3, 5, 10, 8, 7, 9, 6};
//     vector<int> arr2 = {4, 1, 2, 3, 5, 10, 9, 6, 8, 7};
//     for (int i = 0; i < arr1.size(); ++i)
//     {
//         for (int j = i + 1; j < arr2.size(); ++j)
//         {
//             if (arr1[j] < arr1[i]) ++res1;
//             if (arr2[j] < arr2[i]) ++res2;
//         }
//     }
//     cout << (res1 == res2) << '\n';
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
