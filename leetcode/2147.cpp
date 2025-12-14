class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        int n = corridor.size();
        int ok = 1;
        vector<int> cnts;
        int cnt = 0, seatCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (ok && corridor[i] == 'P') {
                ++cnt;
            }
            if (corridor[i] == 'S') {
                if (ok) {
                    cnts.push_back(cnt);
                    cnt = 0;
                }
                ok ^= 1;
                ++seatCnt;
            }
        }

        if (seatCnt & 1 || !seatCnt) {
            return 0;
        }

        cnts.push_back(cnt);
        int sz = cnts.size();
        long long ret = 1;
        for (int i = 1; i < sz - 1; ++i) {
            ret *= (cnts[i] + 1);
            ret %= MOD;
        }
        // for (auto x : cnts) cout << x << ' ';
        return ret;
    }
};
