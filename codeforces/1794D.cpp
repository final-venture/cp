#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n;
const int MAXNUM = 1e6 + 5;
const int MAXN = 2025;

int a[2 * MAXN + 5];
int sieve[MAXNUM + 1] = {0};
int cnt[MAXNUM + 1] = {0};
const int MOD = 998244353;
int dp[2 * MAXN + 5][MAXN + 5] = {0};
int fact[2 * MAXN + 5];

void buildFact() {
    fact[0] = 1;
    for (int i = 1; i <= 2 * MAXN + 2; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void buildSieve() {
    sieve[1] = 1;
    for (int i = 2; i * i <= MAXNUM; ++i) {
        for (int j = i * i; j <= MAXNUM; j += i) {
            sieve[j] = 1;
        }
    }
}

int bin_exp(int base, int exp) {
    int ret = 1;
    while (exp > 0) {
        if (exp & 1) {
            ret *= base;
            ret %= MOD;
        }
        base *= base;
        base %= MOD;
        exp /= 2;
    }
    return ret;
}

int divmod(int a, int b) {
    return a * bin_exp(b, MOD - 2) % MOD;
}

void solve()
{
    buildSieve();
    buildFact();
    cin >> n;
    for (int i = 1; i <= 2*n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    
    vector<int> primes {0};

    int prodOfCompositeFact = 1;
    for (int i = 1; i <= MAXNUM; ++i) {
        if (sieve[i] == 1) {
            prodOfCompositeFact *= fact[cnt[i]];
            prodOfCompositeFact %= MOD;
        }
        else if (sieve[i] == 0 && cnt[i] > 0) {
            primes.push_back(i);
        }
    }
    int toMultiply = divmod(fact[n], prodOfCompositeFact);

    int sz = primes.size() - 1;
    if (sz < n) {
        cout << 0 << '\n';
        return;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= sz; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = divmod(dp[i - 1][j], fact[cnt[primes[i]]]);
            if (j > 0) {
                dp[i][j] += divmod(dp[i - 1][j - 1], fact[cnt[primes[i]] - 1]);
                dp[i][j] %= MOD;
            }
        }
    }

    cout << (toMultiply * dp[sz][n]) % MOD << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

// 2*n integers. Why? because each term in prime factorisation consists of
//  an exponent as well as an integer (2 terms)
// first we need to find the primes in the multiset of 2*n integers.
// we can sieve up to 10^6 to do this.
// If there are less than n unique primes in the multiset, we can output 0

// Otherwise, count for each prime, which occurs k times in the multiset:
//  1. choose the prime as a base: then we can use it in exponents (k - 1) times.
//  2. omit the prime ase a base: then we can use it in exponents k times.

// dp[i] != 0 if and only if number of primes before i is >= to i/2.
// so what if we just put all primes at the beginning of the array?
// We know that if there are less than n primes, it's not possible
// So in the case that it is, just put all n primes at the front.

// Brute force: iterate through all possible sets of n primes. For each set, find how many
//              duplicates there are in the remaining numbers and add C(n, dupes1) + C(n-dupes1, dupes2) + ...
//              to the answer.

// DP: Knapsack
