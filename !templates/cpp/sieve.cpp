#include <bits/stdc++.h>

using namespace std;

struct Sieve {
    vector<int> spf;
    vector<int> primes;

    // Constructor builds the sieve up to N
    Sieve(int n) {
        spf.resize(n + 1);
        // Initialize every number's smallest prime factor to itself
        for (int i = 2; i <= n; ++i) {
            spf[i] = i;
        }
        
        // Sieve out composite numbers
        for (long long i = 2; i * i <= n; ++i) {
            if (spf[i] == i) { // i is prime
                for (long long j = i * i; j <= n; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
        
        // Populate the list of prime numbers
        for (int i = 2; i <= n; ++i) {
            if (spf[i] == i) {
                primes.push_back(i);
            }
        }
    }

    // O(1) Prime Check
    bool isPrime(int n) const {
        if (n < 2 || n >= spf.size()) return false;
        return spf[n] == n;
    }

    // Prime Factorization
    // Returns a list of prime factors (e.g., 12 -> {2, 2, 3})
    // TC: O(log N)
    vector<int> getPrimeFactors(int n) const {
        vector<int> factors;
        while (n > 1) {
            factors.push_back(spf[n]);
            n /= spf[n];
        }
        return factors;
    }
};
