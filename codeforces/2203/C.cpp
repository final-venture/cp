#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int max_bit = 60;

vector<int> bits_m(max_bit);
vector<int> bits_s(max_bit);

bool check(int limit) {
    vector<int> curr_s(bits_s.begin(), bits_s.end());
    vector<int> curr_m(bits_m.begin(), bits_m.end());
    // Valid
    for (int i = 0; i < max_bit - 1; ++i) {
        if (curr_s[i] > 0 && curr_m[i] == 0) {
            curr_s[i + 1] += (curr_s[i] * 2);
            curr_s[i] = 0;
        }
        else if (curr_s[i] > limit && curr_m[i] == 1) {
            int toRemove = curr_s[i] - limit;
            curr_s[i + 1] += toRemove * 2;
            curr_s[i] -= toRemove;
        }
    }

    bool ret = true;

    // for (int i = 0; i < 60; ++i) {
    //     cout << curr_s[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i < 60; ++i) {
    //     cout << curr_m[i] << ' ';
    // }
    // cout << '\n';
    
    for (int i = 0; i < max_bit; ++i) {
        if (curr_s[i] > limit || (curr_s[i] > 0 && curr_m[i] == 0)) {
            ret = false;
        }
    }

    return ret;
}

void solve()
{
    int s, m;
    cin >> s >> m;

    bits_m.assign(max_bit, 0);
    bits_s.assign(max_bit, 0);
    int lsb_m = -1;
    for (int bit = 0; bit < max_bit; ++bit) {
        if (lsb_m == -1 && (m >> bit) & 1) {
            lsb_m = bit;
        }
        
        if ((m >> bit) & 1) {
            bits_m[max_bit - bit - 1] = 1;
        }
    }

    int lsb_s = -1;
    for (int bit = 0; bit < max_bit; ++bit) {
        if (lsb_s == -1 && (s >> bit) & 1) {
            lsb_s = bit;
        }

        if ((s >> bit) & 1) {
            bits_s[max_bit - bit - 1] = 1;
        }
    }

    // Invalid
    if (lsb_m  > lsb_s) {
        cout << -1 << '\n';
        return;
    }

    int l = 0, r = 2e18;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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
