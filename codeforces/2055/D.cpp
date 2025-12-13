#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    // sort(arr.begin(), arr.end());
    double N = n, K = k, L = l;
    double T = arr[0];
    double prev = 0;
    double S = 0; // skipped
    for (int i = 1; i < n; ++i)
    {
        double curr = min({L, arr[i] + T, max(prev + K, (arr[i] - T + prev + K) / 2.0)});
        T += max(0.0, curr - prev - K);
        S += min(K, curr - prev);
        prev = curr;
    }
    S += min(K, L - prev);
    cout << (int)round(2 * (L - S + arr[0])) << '\n';
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
