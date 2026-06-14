#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXA = 1005;

vector<int> sieve, prime;

void buildSieve() {
    sieve.resize(MAXA, 1);
    sieve[0] = 0; sieve[1] = 0;
    for (int i = 2; i < MAXA; ++i) {
        for (int j = i * i; j < MAXA; j += i) {
            sieve[j] = 0;
        }
    }
    for (int i = 2; i < MAXA; ++i) {
        if (sieve[i]) {
            prime.push_back(i);
        }
    }
}

void solve()
{
    int n, e;
    cin >> n >> e;
    int sz = prime.size();
    // int p, q;
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            if (i != j && prime[i] * prime[j] == n) {
                // p = i; q = j;
                // break;
                int tot = (prime[i] - 1) * (prime[j] - 1);
                for (int d = 0; d < MAXA * MAXA; ++d) {
                    if ((d * e - 1) % tot == 0) {
                        cout << d << '\n';
                        return;
                    }
                }
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    buildSieve();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
