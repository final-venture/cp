// at each query, we must find the maximum gap between all pairs of obstacles:
//  if this gap is >= sz, then we can place it
// Store a segment tree with the distance to the previous obstacle.

// For each update, when we place an obstacle at position x, we only have to
//  change the prev[i] for all i > x
// Actually, we only have to change the value of prev on the current block,
// as well as the next obstacle, nxt[x] if it exists.
// remember to place a dummy obstacle at 0

#define LSOne(x) ((x) & (-x))

const int MAXN = 5e4;

class Solution {
private:
    int fenw[MAXN + 5] = {0};
    int arr[MAXN + 5] = {0};
    int query(int r) {
        int ret = 0;
        for (; r > 0; r -= LSOne(r)) {
            ret = max(ret, fenw[r]);
        }
        return ret;
    }

    void update(int t, int v) {
        arr[t] = v;
        for (int i = t; i <= MAXN + 2; i += LSOne(i)) {
            fenw[i] = arr[i];
            for (int j = 1; j < LSOne(i); j <<= 1) {
                fenw[i] = max(fenw[i], fenw[i - j]);
            }
        }
    }
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> obs {1};
        vector<bool> ret;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1] + 1;
                auto prevIt = prev(obs.upper_bound(x));
                update(x, x - (*prevIt));

                auto nextIt = obs.upper_bound(x);
                if (nextIt != obs.end()) {
                    int nextVal = *nextIt;
                    update(nextVal, nextVal - x);
                }

                obs.insert(x);
            }
            else if (q[0] == 2) {
                int x = q[1] + 1, sz = q[2];
                auto prevIt = prev(obs.upper_bound(x));
                int can = max(query(x), x - (*prevIt));
                if (can >= sz) {
                    ret.push_back(true);
                }
                else {
                    ret.push_back(false);
                }
            }
        }

        return ret;
    }
};
