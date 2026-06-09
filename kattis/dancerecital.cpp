#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

const int MAXR = 10;
int a[20];

void solve()
{
    memset(a, 0, sizeof(a));
    int R;
    cin >> R;
    for (int i = 0; i < R; ++i) {
        int mask = 0;
        string s;
        cin >> s;
        for (char c : s) {
            int bit = c - 'A';
            mask |= (1 << bit);
        }
        a[i] = mask;
    }
    sort(a, a + R);

    int ret = 300;
    do {
        int cand = 0;
        for (int i = 1; i < R; ++i) {
            cand += (__builtin_popcount(a[i] & a[i - 1]));
            if (cand > ret) {
                break;
            }
        }
        ret = min(ret, cand);
    } while (next_permutation(a, a + R));

    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
