class Solution {
public:
    int smallestNumber(int n) {
        int res = 1;
        for (int i = 0; i < 10; ++i)
            {
                if (res - 1 >= n)
                    break;
                res *= 2;
            }
        return res - 1;
    }
};
