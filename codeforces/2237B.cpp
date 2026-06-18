#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<bool> used;

void solve()
{
    int n;
    
    
    cin >> n;
    used.assign(n, false);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int j = 0; j < n; j++) {
        int foundIdx = -1;
        int lftIdx = 0;

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                if (a[i] <= b[j]) {
                    foundIdx = i;
                    swaps += lftIdx;
                    used[i] = true;
                    break;
                }
                lftIdx++;
            }
        }

        if (foundIdx == -1) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << swaps << "\n";
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
