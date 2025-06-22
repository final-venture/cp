class Solution
{
public:
    int maxDifference(string s)
    {
        vector<int> cnts(26, 0);
        for (char c : s)
        {
            ++cnts[c - 'a'];
        }

        vector<int> odds, evens;
        for (int freq : cnts)
        {
            if (freq > 0)
            {
                if (freq % 2 == 1)
                    odds.push_back(freq);
                else
                    evens.push_back(freq);
            }
        }

        if (odds.empty() || evens.empty())
            return -1;

        int maxDiff = INT_MIN;
        for (int odd : odds)
        {
            for (int even : evens)
            {
                maxDiff = max(maxDiff, odd - even);
            }
        }

        return maxDiff;
    }
};
