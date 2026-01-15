class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int nn = hBars.size(), mm = vBars.size();
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int csc1 = 1, csc2 = 1;
        int cand = 1;
        for (int i = 1; i < nn; ++i) {
            if (hBars[i] == hBars[i - 1] + 1) {
                ++cand;
            }
            else {
                cand = 1;
            }
            csc1 = max(csc1, cand);
        }
        cand = 1;
        for (int i = 1; i < mm; ++i) {
            if (vBars[i] == vBars[i - 1] + 1) {
                ++cand;
            }
            else {
                cand = 1;
            }
            csc2 = max(csc2, cand);
        }
        return (min(csc1, csc2) + 1) * (min(csc1, csc2) + 1);
    }
};
