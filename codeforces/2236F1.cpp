#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<int> sieve;
const int MAXA = 5e5 + 5;
const int MOD = 1e9 + 7;
int cnt[MAXA];

void buildSieve() {
    sieve.resize(MAXA, 1);
    sieve[0] = 0; sieve[1] = 0;
    for (int i = 2; i < MAXA; ++i) {
        for (int j = i * i; j < MAXA; j += i) {
            sieve[j] = 0;
        }
    }
}

// prime factor each number, 
// TC1:
//  4 1
//  2 3 1 4
// { {1, 2}, {1, 3}, {1}, {1, 2, 4} }
// { {2}, {3}, {}, {2^2} }
// pfs: {2, 3}

// {1, 4}, {1, 2}, {1, 1}, {2, 1}.

// 4 = 2^2, 2 = 2
// pfs: {2}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> prime;
    for (int i = 0; i < n; ++i) {
        for (int j = 2; j * j <= a[i]; ++j) {
            if (!sieve[j]) {
                continue;
            }
            if (a[i] % j == 0) {
                prime.push_back(j);
            }
            while (a[i] % j == 0) {
                a[i] /= j;
                cnt[j]++;
            }
        }
        if (sieve[a[i]]) {
            prime.push_back(a[i]);
            cnt[a[i]]++;
        }
    }
    sort(prime.begin(), prime.end());
    prime.erase(unique(prime.begin(), prime.end()), prime.end());

    // for (int i = 0; i < 10; ++i) {
    //     cout << cnt[i] << ' ';
    // }

    int ret = 1;
    for (int i = 0; i < prime.size(); ++i) {
        // cerr << prime[i] << ' ';
        ret *= cnt[prime[i]];
        ret %= MOD;
        cnt[prime[i]] = 1;
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    buildSieve();
    fill(cnt, cnt + MAXA, 1);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
