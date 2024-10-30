class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int ttotal = 0;
        int total = 0;
        int i = 0;
        int j = 0;

        while (j < gas.size())
        {
            int cand = gas[j] - cost[j];
            ttotal += cand;
            total += cand;
            if (total < 0)
            {
                i = j + 1;
                total = 0;
            }
            ++j;
        }
        return (ttotal < 0) ? -1 : i;
    }
};
