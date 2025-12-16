class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ret = 0;
        long long cont = 1;
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                ++cont;
            }
            else {
                ret += cont * (cont + 1) / 2;
                cont = 1;
            }
        }
        ret += cont * (cont + 1)/2;
        return ret;
    }
};
