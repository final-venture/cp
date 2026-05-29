const int MAXN = 5e5;
int trie[MAXN + 5][26];
int minLen[MAXN + 5];
int minIdx[MAXN + 5];

class Solution {
private:
    int timer = 1;

    void insert(int idx, string& s) {
        int sz = s.size();
        int curr = 1;
        if (minLen[1] > sz) {
            minLen[1] = sz;
            minIdx[1] = idx;
        }
        for (int i = 0; i < sz; ++i) {
            int c = s[i] - 'a';
            if (!trie[curr][c]) {
                trie[curr][c] = ++timer;
                // printf("inserted node %d via. edge %c from node %d\n", timer, (char)(c + 'a'), curr);
            }
            curr = trie[curr][c];
            
            if (minLen[curr] > sz) {
                minLen[curr] = sz;
                minIdx[curr] = idx;
            }
        }
    }

    // find longest common suffix
    // if tied, take the one with the smallest length
    // if tied again, take the one that occurred earlier.
    int query(string& s) {
        int sz = s.size();
        int curr = 1;
        int ret = minIdx[1];
        for (int i = 0; i < sz; ++i) {
            int c = s[i] - 'a';
            if (!trie[curr][c]) {
                return ret;
            }
            curr = trie[curr][c];
            ret = minIdx[curr];
        }
        return ret;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size(), m = wordsQuery.size();
        int totalSz = 0;

        for (auto& s : wordsContainer) {
            reverse(s.begin(), s.end());
            totalSz += s.size();
        }
        for (auto& s : wordsQuery) {
            reverse(s.begin(), s.end());
        }

        for (int i = 1; i <= totalSz + 3; ++i) {
            for (int j = 0; j < 26; ++j) {
                trie[i][j] = 0;
            }
            minLen[i] = 1e9;
            minIdx[i] = -1;
        }

        for (int i = 0; i < n; ++i) {
            insert(i, wordsContainer[i]);
        }

        vector<int> ret(m);
        for (int i = 0; i < m; ++i) {
            ret[i] = query(wordsQuery[i]);
        }

        // for (int i = 1; i <= totalSz; ++i) {
        //     cout << minLen[i] << ' ' << minIdx[i] << '\n';
        // }

        return ret;
    }
};
