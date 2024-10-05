class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> arrSorted(arr);
        sort(arrSorted.begin(), arrSorted.end());
        unordered_map<int, int> n2r;
        int curr = 1;
        for (int i = 0; i < n; i++)
        {
            if (!(n2r.count(arrSorted[i])))
            {
                n2r[arrSorted[i]] = curr;
                curr += 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            arrSorted[i] = n2r[arr[i]];
        }
        return arrSorted;
    }
};
