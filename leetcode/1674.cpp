class Solution {
public:
    void addRange(int l, int r, int d, vector<int>& v) {
        v[l] += d;
        v[r + 1] -= d;
    }

    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> minMovesFor(2*limit + 2, 0);

        // let the comp. pairs be (a, b)
        // using 0 operations, you can only get a + b.
        // using 1 operation, lb is min(a, b) + 1, ub is max(a, b) + limit
        // otherwise, using 2 operations, you can get [2, 3, ..., limit * 2]

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i], b = nums[n - 1 - i];
            // 2 operations:
            addRange(2, limit * 2, 2, minMovesFor);

            // 1 operation:
            addRange(min(a, b) + 1, max(a, b) + limit, -1, minMovesFor);

            // 0 operations:
            addRange(a + b, a + b, -1, minMovesFor);
        }

        int d = 0;
        for (int i = 2; i < 2 * limit + 2; ++i) {
            d += minMovesFor[i];
            minMovesFor[i] = d;
        }

        return *min_element(minMovesFor.begin() + 2, minMovesFor.end() - 1);
    }
};

