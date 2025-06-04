class Solution {
public:
    long long coloredCells(int n) {
        long long nn = n;
        return 2*nn*nn-2*nn+1;
    }
};
