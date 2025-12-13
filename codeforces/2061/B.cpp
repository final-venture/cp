#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int i = 1, j = 3;
    while (j < n)
    {
        if (arr[i] != arr[i - 1] && arr[j] != arr[j - 1] && arr[j - 1] != arr[i])
        {
            ++i;
            ++j;
            continue;
        }
        vector<int> cand{arr[i - 1], arr[i], arr[j - 1], arr[j]};
        sort(cand.begin(), cand.end());
        if (cand[0] + cand[1] + cand[2] > cand[3])
        {
            for (auto x : cand)
                cout << x << ' ';
            cout << '\n';
            return;
        }
        ++j;
    }
    cout << -1 << '\n';
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
