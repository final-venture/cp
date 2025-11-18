class Solution {
private:
    vector<long long> cntw0;
    string nStr;
    int getDigit(int digit) {
        return nStr[digit] - '0';
    }
    long long pwr(long long base, int exp) {
        if (exp == 0) return 1;
        long long ret = base;
        for (int i = 1; i < exp; ++i) {
            ret *= base;
        }
        return ret;
    }
    int getDigitCnt(long long n) {
        int ret = 0;
        for (; n > 0; n /= 10) {
            ++ret;
        }
        return ret;
    }
public:
    long long countDistinct(long long n) {
        cntw0.resize(20, 0);
        for (int i = 2; i <= 18; ++i) {
            long long free = (long long)pwr(10, i-2);
            long long last = cntw0[i - 1];
            cntw0[i] = (free + last) * 9;
        }
        // for (int i = 0; i <= 18; ++i) {
        //     cout << cntw0[i] << ' ';
        // }
        int digits = getDigitCnt(n);
        // cout << digits;
        long long with0 = 0;

        for (int i = 0; i < digits; ++i) {
            with0 += cntw0[i];
        }

        // cout << with0 << '\n';
        nStr = to_string(n);
        bool hasLZ = false; // has leading zero

        for (int d = 0; d < digits; ++d) {
            int start = (d == 0) ? 1 : 0;
            long long currDigit = getDigit(d);
            long long power = digits - d - 1;
            for (int i = start; i < currDigit; ++i) {
                if (hasLZ || i == 0) {
                    long long hasZeroCnt = (long long)pwr(10, power);
                    with0 += hasZeroCnt;
                    // cout << d << ' ' << i << ' ' << power << ' ' << hasZeroCnt << '\n';
                }
                else if (!hasLZ) {
                    long long totalCnt = (long long)pwr(10, power);
                    long long withoutZeroCnt = (long long)pwr(9, power);
                    long long hasZeroCnt = totalCnt - withoutZeroCnt;
                    cout << totalCnt << '  ' << withoutZeroCnt << '\n';
                    // cout << hasZeroCnt << ' ' << with0 << '\n';
                    with0 += hasZeroCnt;
                    // cout << hasZeroCnt << ' ' << with0 << '\n';
                    // cout << d << ' ' << i << ' ' << power << ' ' << hasZeroCnt << ' ' << with0 << '\n';
                }
            }
            if (currDigit == 0 && !hasLZ) {
                hasLZ = true;
                ++with0;
            }
        }

        // cout << n << ' ' << with0 << '\n';
        return n - with0;
    }
};
