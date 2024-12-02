class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int curr = 1;
        int i = 0;
        while (i < sentence.size()) {
            int j = 0;
            while (sentence[i] == searchWord[j]) {
                if (j == searchWord.size() - 1)
                    return curr;
                ++j;
                ++i;
            }
            while (i < sentence.size() && sentence[i] != ' ') {
                ++i;
            }
            ++i;
            ++curr;
        }
        return -1;
    }
};
