#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n;
vector<string> colour;
int ops;

int moveColour(int src, int dst, int c = 0) {
    ++ops;
    cout << src << ' ' << dst << ' ' << colour[c] << endl;
    int ret;
    cin >> ret;
    return ret;
}

void outputAns(int ans) {
    cout << ans << " !" << endl;
}

void solve()
{
    ops = 0;
    cin >> n;
    colour.resize(n + 1);
    colour[0] = "all";
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        cin >> colour[i];
    }

    int curr = 1, nxt = 2;
    while (ops + n + 1 < 1199) {
        for (int i = 1; i <= n; ++i) {
            moveColour(curr, nxt, i);
        }
        moveColour(curr, 3);
        swap(curr, nxt);
    }

    int ret = moveColour(curr, nxt);
    outputAns(ret);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
