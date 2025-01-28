#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

int n, k;
vector<int> arr;

bool check(int x)
{
    int total = 0;
    int accu = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        accu += arr[r];
        while (accu >= x)
        {
            accu -= arr[l];
            ++l;
        }
        total += (r - l + 1);
        ++r;
    }
    int gtoe = n * (n + 1) / 2 - total;
    return (gtoe >= k); // number of subarrays greater than or equal to m <= k
}

void solve()
{
    cin >> n;
    cin >> k;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int l = 0, r = 2e14;
    while (l < r)
    {
        int m = l + (r - l + 1) / 2;
        if (check(m))
        {
            l = m;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << l;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
