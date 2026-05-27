#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXN = 1e5;
int a[MAXN + 5];
int n;

void solve()
{
    cin >> n;
    vector<int> citCnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        citCnt[min(n, a[i])]++;
    }
    
    int cnt = 0;
    for (int i = n; i >= 0; --i) {
        cnt += citCnt[i];
        if (cnt >= i) {
            cout << i << '\n';
            break;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
