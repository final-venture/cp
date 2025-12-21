class Solution
{
public:
    int mirrorDistance(int n)
    {
        string numStr = to_string(n);
        reverse(numStr.begin(), numStr.end());
        int rev = stoi(numStr);
        return abs(n - rev);
    }
};
