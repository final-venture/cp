#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    string orig;
    cin >> orig;
    string mut;
    cin >> mut;

    int oSz = orig.size();
    int mSz = mut.size();
    int ol = 0, orr = oSz - 1;
    int ml = 0, mr = mSz - 1;

    while (ol <= orr && ml <= mr && orig[ol] == mut[ml]) {
        ++ol;
        ++ml;
    }

    while (ol <= orr && ml <= mr && orig[orr] == mut[mr]) {
        --mr;
        --orr;
    }

    cout << (mr - ml + 1) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
