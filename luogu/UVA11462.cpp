#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n;
const int MAXN = 2e6;
int a[MAXN + 5];
int cnt[102] = {0};

void solve()
{
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    // for (int i = 1; i < 102; ++i) {
    //     cnt[i] = cnt[i] + cnt[i - 1];
    // }

    int curr = 0;
    for (int i = 0; i < 102; ++i) {
        while (cnt[i] > 0) {
            a[curr] = i;
            --cnt[i];
            ++curr;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i < n - 1) {
            cout << ' ';
        }
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        solve();
    }
    return 0;
}
