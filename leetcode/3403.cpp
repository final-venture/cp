class Solution {
public:
    struct suffix {
        int index;  // To store original index
        int rank[2];  // To store ranks and next rank pair
    };

    // A comparison function used by sort() to compare two suffixes
    static bool cmp(const suffix &a, const suffix &b) {
        return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1]) : (a.rank[0] < b.rank[0]);
    }

    // This is the main function that takes a string 'txt' of size n as an
    // argument, builds and returns the suffix array for the given string
    std::vector<int> buildSuffixArray(const std::string &txt, int n) {
        // A vector to store suffixes and their indexes
        std::vector<suffix> suffixes(n);

        // Store suffixes and their indexes in an array of structures
        for (int i = 0; i < n; i++) {
            suffixes[i].index = i;
            suffixes[i].rank[0] = txt[i] - 'a';
            suffixes[i].rank[1] = (i + 1 < n) ? (txt[i + 1] - 'a') : -1;
        }

        // Sort the suffixes using the comparison function
        std::sort(suffixes.begin(), suffixes.end(), cmp);

        // At this point, all suffixes are sorted according to first 2 characters
        std::vector<int> ind(n);  // This array is needed to get the index in suffixes[]
        // from original index
        for (int k = 4; k < 2 * n; k = k * 2) {
            int rank = 0;
            int prev_rank = suffixes[0].rank[0];
            suffixes[0].rank[0] = rank;
            ind[suffixes[0].index] = 0;

            // Assigning rank to suffixes
            for (int i = 1; i < n; i++) {
                if (suffixes[i].rank[0] == prev_rank &&
                        suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                    suffixes[i].rank[0] = rank;
                } else {
                    prev_rank = suffixes[i].rank[0];
                    suffixes[i].rank[0] = ++rank;
                }
                ind[suffixes[i].index] = i;
            }

            // Assign next rank to every suffix
            for (int i = 0; i < n; i++) {
                int nextindex = suffixes[i].index + k / 2;
                suffixes[i].rank[1] = (nextindex < n) ? suffixes[ind[nextindex]].rank[0] : -1;
            }

            // Sort the suffixes according to first k characters
            std::sort(suffixes.begin(), suffixes.end(), cmp);
        }

        // Store indexes of all sorted suffixes in the suffix array
        std::vector<int> suffixArr(n);
        for (int i = 0; i < n; i++)
            suffixArr[i] = suffixes[i].index;

        return suffixArr;
    }

    string answerString(string word, int numFriends) {
        int n = word.size();
        int longest = n - numFriends + 1; // misses end
        if (numFriends == 1) return word;

        vector<int> sfxarr = buildSuffixArray(word, n);
        int l = sfxarr.back();
        int r = l + longest;
        string ret;
        for (int i = l; i < min(r, n); ++i)
        {
            ret += word[i];
        }
        return ret;
    }
};
