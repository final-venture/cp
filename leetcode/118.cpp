class Solution {
private:
    vector<vector<int>> ret;
    void dfs(int i) {
        if (i == 0) {
            ret.push_back({1});
            return;
        }
        dfs(i - 1);
        vector<int> cand {1};
        vector<int>& lst = ret.back();
        for (int i = 1; i < lst.size(); ++i) {
            cand.push_back(lst[i] + lst[i - 1]);
        }
        cand.push_back(1);
        ret.push_back(cand);
    }
public:
    vector<vector<int>> generate(int numRows) {
        dfs(numRows - 1);
        return ret;
    }
};
