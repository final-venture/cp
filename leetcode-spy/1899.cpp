class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        vector<bool> resvec(3, false);
        for (auto &triplet : triplets)
        {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2])
            {
                continue;
            }
            for (int i = 0; i < 3; ++i)
            {
                if (triplet[i] == target[i])
                {
                    resvec[i] = true;
                }
            }
        }
        if (resvec[0] && resvec[1] && resvec[2])
        {
            return true;
        }
        return false;
    }
};
