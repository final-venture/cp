#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

void solve()
{
    int x, w;
    cin >> x >> w;
    vector<int> arr(x);
    for (int i = 0; i < x; ++i)
    {
        cin >> arr[i];
    }
    int ret = accumulate(arr.begin(), arr.end(), 0);
    for (int i = 0; i < w; ++i)
    {
        int k;
        cin >> k;
        int l = 0, r = k - 1;
        int cand = accumulate(arr.begin(), arr.begin() + k, 0);
        // cout << cand << ' ';
        int curr = cand;
        while (r < x - 1)
        {
            curr -= arr[l];
            ++l;
            ++r;
            curr += arr[r];
            cand = max(cand, curr);
        }
        // cout << cand << '\n';
        if (cand > 0)
            ret += cand;
    }
    cout << ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
