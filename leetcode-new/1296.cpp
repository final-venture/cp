class Solution
{
public:
    bool isPossibleDivide(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize)
            return false;

        sort(hand.begin(), hand.end());
        unordered_map<int, int> n2c;
        for (int card : hand)
        {
            n2c[card]++;
        }
        for (int card : hand)
        {
            if (!n2c[card])
                continue;
            for (int i = 0; i < groupSize; ++i)
            {
                if (--n2c[card + i] < 0)
                    return false;
            }
        }
        return true;
    }
};
