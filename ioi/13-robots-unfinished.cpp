#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    int A, B, T;
    int X[A], Y[B], W[T], S[T];
    cin >> A >> B >> T;
    for (int i = 0; i < A; ++i)
    {
        cin >> X[i];
    }
    for (int i = 0; i < B; ++i)
    {
        cin >> Y[i];
    }
    for (int i = 0; i < T; ++i)
    {
        cin >> W[i];
        cin >> S[i];
    }
    sort(W, W + T); // weight
    sort(X, X + A); // weak
    sort(S, S + T); // size
    sort(Y, Y + B); // small
    int[]
    int l = 0, r = T;
    while (l <= r)
    {
        int time = 0;
        mid = l + (r - l) / 2;

    }
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
