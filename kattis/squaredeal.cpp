#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    vector<pair<int, int>> rct(3);
    int tA = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> rct[i].first >> rct[i].second;
        tA += rct[i].first * rct[i].second;
    }
    int S = round(sqrtl(tA));
    if (S * S != tA) {
        cout << "NO" << '\n';
        return;
    }

    sort(rct.begin(), rct.end());
    do {
        auto [w0, h0] = rct[0];
        auto [w1, h1] = rct[1];
        auto [w2, h2] = rct[2];
        for (int i = 0; i < 8; ++i) {
            if (i & 1) {
                swap(w0, h0);   
            }
            if (i & 2) {
                swap(w1, h1);
            }
            if (i & 4) {
                swap(w2, h2);
            }
            if (h0 == S && h1 == S && h2 == S && w0 + w1 + w2 == S) {
                cout << "YES" << '\n';
                return;
            }
            else if (h0 == S) {
                if (h1 + h2 == S && w1 == w2 && w2 + w0 == S) {
                    cout << "YES" << '\n';
                    return;  
                }
            }
            if (i & 1) {
                swap(w0, h0);   
            }
            if (i & 2) {
                swap(w1, h1);
            }
            if (i & 4) {
                swap(w2, h2);
            }
        }
    } while (next_permutation(rct.begin(), rct.end()));
    cout << "NO" << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
