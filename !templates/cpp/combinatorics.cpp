#include <vector>

using namespace std;

struct Combinatorics {
    int n;
    long long mod;
    vector<long long> fact;
    vector<long long> inv_fact;

    // Initialize with the maximum N you need, and the prime MOD
    Combinatorics(int _n, long long _mod) : n(_n), mod(_mod) {
        fact.assign(n + 1, 1);
        inv_fact.assign(n + 1, 1);
        
        // 1. Precompute factorials
        for (int i = 1; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        
        // 2. Precompute inverse factorials using Fermat's Little Theorem
        inv_fact[n] = mod_exp(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; --i) {
            inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
        }
    }

    // TC: O(log(exp))
    long long mod_exp(long long base, long long exp) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    // TC: O(1)
    long long C(int n, int r) {
        if (r < 0 || r > n || n < 0) return 0;
        return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
    }

    // TC: O(1)
    long long P(int n, int r) {
        if (r < 0 || r > n || n < 0) return 0;
        return fact[n] * inv_fact[n - r] % mod;
    }
};
