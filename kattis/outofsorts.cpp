#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, m, a, c, x0;
    cin >> n >> m >> a >> c >> x0;
    vector<int> arr(n + 1);
    arr[0] = x0;
    for (int i = 1; i <= n; ++i) {
        arr[i] = (arr[i - 1] * a + c) % m;
    }
    vector<int> ret;
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = n;
        int its = 0;
        while (its++ < 100 && l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < arr[i]) {
                l = mid + 1;
            }
            else if (arr[mid] > arr[i]) {
                r = mid - 1;
            }
            else {
                ret.push_back(arr[i]);
            }
        }
    }
    ret.erase(unique(ret.begin(), ret.end()), ret.end());

    cout << (int)ret.size() << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
