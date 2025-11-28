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
    int n, m;
    cin >> n >> m;
    int nums[m + 1];
    int rank[n + 1];
    memset(rank, -1, sizeof(rank));
    for (int i = 1; i < m + 1; ++i)
    {
        cin >> nums[i];
    }
    sort(nums + 1, nums + 1 + m, greater<int>());
    rank[1] = 1;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = i * 2; j < n + 1; j += i)
        {
            rank[j] = rank[i] + 1;
        }
    }
    int maxx = *max_element(rank + 1, rank + 1 + n);
    if (maxx > m)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i < n + 1; ++i)
    {
        cout << nums[rank[i]] << ' ';
    }
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
