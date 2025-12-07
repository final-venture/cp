class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> adj1;
    unordered_map<string, vector<pair<string, double>>> adj2;
    unordered_set<string> seen1;
    unordered_set<string> seen2;
    unordered_map<string, double> c2r1;
    unordered_map<string, double> c2r2;
    string initialCurrency;
    double ret = 1;
public:
    void dfs1(string cur, double qty)
    {
        if (seen1.find(cur) != seen1.end()) return;
        seen1.insert(cur);
        dfs2(cur, qty);
        for (auto& [nei, rate] : adj1[cur])
        {
            dfs1(nei, qty * rate);
        }
        seen1.erase(cur);
    }
    void dfs2(string cur, double qty)
    {
        if (seen2.find(cur) != seen2.end())
            return;
        seen2.insert(cur);
        if (cur == initialCurrency)
            ret = max(ret, qty);
        for (auto& [nei, rate] : adj2[cur])
        {
            dfs2(nei, qty * rate);
        }
        seen2.erase(cur);
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        this -> initialCurrency = initialCurrency;
        for (int i = 0; i < pairs1.size(); ++i)
        {
            adj1[pairs1[i][0]].push_back({pairs1[i][1], rates1[i]});
            adj1[pairs1[i][1]].push_back({pairs1[i][0], (1 / rates1[i])});
        }
        for (int i = 0; i < pairs2.size(); ++i)
        {
            adj2[pairs2[i][0]].push_back({pairs2[i][1], rates2[i]});
            adj2[pairs2[i][1]].push_back({pairs2[i][0], (1 / rates2[i])});
        }
        dfs1(initialCurrency, 1);
        return ret;
    }
};