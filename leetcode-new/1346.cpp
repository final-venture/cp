class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s;
        for (int i = 0; i < n; ++i)
        {
            if (s.count(arr[i] * 2) || (!(arr[i] & 1) && s.count(arr[i] / 2))) return true;
            s.insert(arr[i]);
        }
        return false;
    }
};
