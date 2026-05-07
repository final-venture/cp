#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int a, b;
    cin >> a >> b;

    int best = 0;
    int layers = 0;
    int used_a = 0, used_b = 0;
    int use_a = 1, use_b = 0;
    while (used_a + use_a <= a && used_b + use_b <= b) {
        ++layers;
        used_a += use_a;
        used_b += use_b;
        use_a *= 2;
        use_b *= 2;
        swap(use_a, use_b);
    }
    best = max(best, layers);

    layers = 0;
    used_a = 0; used_b = 0;
    use_a = 0, use_b = 1;
    while (used_a + use_a <= a && used_b + use_b <= b) {
        ++layers;
        used_a += use_a;
        used_b += use_b;
        use_a *= 2;
        use_b *= 2;
        swap(use_a, use_b);
    }
    best = max(best, layers);

    cout << best << '\n';
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
