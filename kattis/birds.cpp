#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int l, d, n;
    cin >> l >> d >> n;
    int ret = 0;
    vector<int> bird(n);
    for (int i = 0; i < n; ++i) {
        cin >> bird[i];
    }
    sort(bird.begin(), bird.end());
    if (n == 0 || bird[0] >= 6 + d) {
        bird.push_back(6);
        ++ret;
    }
    sort(bird.begin(), bird.end());
    if (n == 0 || bird.back() <= l - 6 - d) {
        bird.push_back(l - 6);
        ++ret;
    }
    sort(bird.begin(), bird.end());

    int sz = bird.size();
    for (int i = 1; i < sz; ++i) {
        ret += max(0LL, (bird[i] - bird[i - 1]) / d - 1);
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
