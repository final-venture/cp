#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    int acnt = 0, bcnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            a[i] = 1;
            ++acnt;
        }
        else {
            a[i] = -1;
            ++bcnt;
        }
    }

    // how many a's we must remove
    int delta = acnt - bcnt;
    if (delta == 0) {
        cout << 0 << '\n';
        return;
    }

    // currPfx - pfx[j] = delta;
    int best = INT_MAX;
    unordered_map<int, int> n2i = {{0, -1}};
    int currPfx = 0;
    for (int i = 0; i < n; ++i) {
        currPfx += a[i];
        int needed = currPfx - delta;
        
        if (n2i.find(needed) != n2i.end()) {
            int prevIdx = n2i[needed];
            best = min(best, i - prevIdx);
        }
        n2i[currPfx] = i;
    }
    
    cout << (best < n ? best : -1) << '\n';
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
