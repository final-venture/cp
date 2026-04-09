class Solution {
public:
    unordered_map<int, string> num2str;
    string process_hundred(string& toProcess) {
        int n = toProcess.size();
        int onesDigit = toProcess[n - 1] - '0';
        int tensDigit = 0;
        int hundredsDigit = 0;
        if (n >= 2) {
            tensDigit = toProcess[n - 2] - '0';
        }
        if (n >= 3) {
            hundredsDigit = toProcess[n - 3] - '0';
        }

        string ret;
        if (n >= 3 && hundredsDigit != 0) {
            ret += num2str[hundredsDigit] + " Hundred ";
        }
        if (n >= 2 && tensDigit != 0) {
            int specialTwoDigitNum = tensDigit * 10 + onesDigit;
            if (11 <= specialTwoDigitNum && specialTwoDigitNum <= 19) {
                ret += num2str[specialTwoDigitNum] + " ";
                return ret;
            }
            else if (tensDigit > 0) {
                ret += num2str[tensDigit * 10] + " ";
            }
        }
        if (n >= 1 && onesDigit != 0) {
            ret += num2str[onesDigit] + " ";
        }
        return ret;
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        num2str = {
            {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, 
            {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, 
            {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"},
            {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"},
            {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"},
            {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"},
            {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
        };

        string numStr = to_string(num);
        int n = numStr.size();

        vector<string> toProcess;
        for (int ed = n - 1; ed >= 0; ed -= 3) {
            int st = max(0, ed - 2);
            string cand = numStr.substr(st, ed - st + 1);
            toProcess.push_back(cand);
        }
        reverse(toProcess.begin(), toProcess.end());

        // for (auto x : toProcess) {
        //     cout << x << ' ';
        // }
        // cout << '\n';

        string ret;
        int nn = toProcess.size();
        for (int order = nn; order >= 1; --order) {
            string hundredStr = process_hundred(toProcess[nn - order]);
            if (hundredStr != "") {
                if (order == 4) {
                    hundredStr += "Billion ";
                }
                else if (order == 3) {
                    hundredStr += "Million ";
                }
                else if (order == 2) {
                    hundredStr += "Thousand ";
                }
                ret += hundredStr;
            }
        }
        ret.pop_back();

        return ret;
    }
};
