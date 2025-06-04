class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;

        int n = word.size();
        char maxx = *max_element(word.begin(), word.end());
        vector<int> idxs;

        for (int i = 0; i < n; i++) {
            if (word[i] == maxx) {
                idxs.push_back(i);
            }
        }

        string ret = "";
        for (auto idx : idxs) {
            string cand;
            int k = numFriends - idx;
            for (int i = idx; i < n; i++) {
                if (i <= n - k) cand += word[i];
            }
            ret = max(ret, cand);
        }
        return ret;
    }
};
