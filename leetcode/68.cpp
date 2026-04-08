class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        int n = words.size();
        int timer = 0;
        vector<string> ret;
        while (i < n) {
            int usedWidth = 0;
            bool notFirst = false;
            vector<string> line;
            while (i < n && usedWidth + notFirst + words[i].size() <= maxWidth) {
                int widthToUse = notFirst + words[i].size();
                notFirst = true;
                line.push_back(words[i]);
                usedWidth += widthToUse;
                ++i;
            }

            int remWidth = maxWidth - usedWidth;
            // printf("line %d: %d\n", ++timer, remWidth);
            string final_line;

            if (i != n) {
                if (line.size() == 1) {
                    for (int i = 0; i < remWidth; ++i) {
                        line[0].push_back(' ');
                    }
                    ret.push_back(line[0]);
                    continue;
                }

                // the number of slots for spaces is max(1, line.size() - 1)
                int spaceSlots = max(1, (int)line.size() - 1);
                // count of spaces per slot
                int spaceCnt = remWidth / spaceSlots;
                // for the first slotsWithExtra spaces, we need to add an extra space
                int slotsWithExtra = remWidth % spaceSlots;

                for (int i = 0; i < line.size() - 1; ++i) {
                    for (int j = 0; j < line[i].size(); ++j) {
                        final_line.push_back(line[i][j]);
                    }
                    final_line.push_back(' ');
                    for (int j = 0; j < spaceCnt; ++j) {
                        final_line.push_back(' ');
                    }
                    if (i < slotsWithExtra) {
                        final_line.push_back(' ');
                    }
                }
                for (int j = 0; j < line.back().size(); ++j) {
                    final_line.push_back(line.back()[j]);
                }
        
                ret.push_back(final_line);
            }
            else {
                for (int i = 0; i < line.size() - 1; ++i) {
                    for (int j = 0; j < line[i].size(); ++j) {
                        final_line.push_back(line[i][j]);
                    }
                    final_line.push_back(' ');
                }
                for (int j = 0; j < line.back().size(); ++j) {
                    final_line.push_back(line.back()[j]);
                }
                for (int j = 0; j < remWidth; ++j) {
                    final_line.push_back(' ');
                }
                ret.push_back(final_line);
            }
        }
        return ret;
    }
};
