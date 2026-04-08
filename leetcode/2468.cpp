class Solution {
private:
    long long getDigits(long long x) {
        long long ret = 0;
        while (x) {
            x /= 10;
            ++ret;
        }
        return ret;
    }

public:
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        int idx = 0;
        int currMsg = 1;
        int maxMessages = -1;
        vector<string> ret;

        // Compute max message count
        int runningTotal = 0;
        for (int m = 1; m <= 1e4; ++m) {
            runningTotal += getDigits(m);
            int used = runningTotal + m * (3 + getDigits(m));
            int free = limit * m - used;
            if (free >= n) {
                maxMessages = m;
                break;
            }
        }

        if (maxMessages == -1) {
            return {};
        }

        while (idx < n) {
            int currSize = to_string(currMsg).size() + to_string(maxMessages).size() + 3;
            if (currSize >= limit) {
                return {};
            }
            string cand;
            while (idx < n && currSize < limit) {
                cand.push_back(message[idx]);
                ++idx;
                ++currSize;
            }
            cand += ("<" + to_string(currMsg) + "/" + to_string(maxMessages) + ">");

            ++currMsg;
            ret.push_back(cand);
        }

        return ret;
    }
};