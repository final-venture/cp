#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    vector<int> wanted(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    for (int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        wanted[x] = 1;
    }
    int ret = 0;
    vector<pair<int, int>> arr2;
    while (arr.size() > 1)
    {
        int nn = arr.size();
        for (int i = 1; i < nn; i += 2)
        {
            int elim = i;
            int rem = i - 1;
            if (arr[i].first > arr[i - 1].first)
            {
                swap(elim, rem);
            }
            arr2.push_back(arr[rem]);
            if (wanted[arr[elim].second])
            {
                ++ret;
                wanted[arr[elim].second] = 0;
                wanted[arr[rem].second] = 0;
            }
        }
        arr = move(arr2);
        arr2.clear();
    }
    if (wanted[arr[0].second])
    {
        ++ret;
    }
    cout << ret;
}

signed main()
{
#ifndef LOCAL
    freopen("busin.txt", "r", stdin);
    freopen("busout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
