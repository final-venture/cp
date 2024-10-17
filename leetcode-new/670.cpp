class Solution
{
public:
    int maximumSwap(int num)
    {
        string numStr = to_string(num);
        int n = numStr.size();

        vector<int> last(10, -1);
        for (int i = 0; i < n; i++)
        {
            last[numStr[i] - '0'] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int dgt = numStr[i] - '0';
            for (int j = 9; j > dgt; j--)
            {
                if (last[j] > i)
                {
                    swap(numStr[i], numStr[last[j]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};
